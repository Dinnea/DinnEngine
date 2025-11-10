#include "dnpch.h"
#include "Application.h"
#include "glfw_glad.h"
#include "Rendering/SpriteRenderer.h"
#include "Rendering/Texture.h"
#include <queue>

namespace Dinn
{
	Application* Application::instance = nullptr;

	Application::Application()
	{
		instance = this;

		isRunning = false;
		maxFrameRate = 60;
		lastFrame = Time::Now();

		window = std::unique_ptr<Window>(Window::Create()); //open gl loaded
		window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));

		assetManager = std::make_unique<AssetManager>();

		spriteRenderer = std::make_unique<SpriteRenderer>();
		spriteRenderer->SetProjection(window->GetWidth(), window->GetHeight());
	}

	Application::~Application()
	{
		gameObjects.clear();

		spriteRenderer.reset();
		assetManager.reset();
		window.reset();

		glfwTerminate();
		instance = nullptr;
	}

	void Application::Run()
	{
		isRunning = true;

		while (isRunning)
		{

			double currentTime = Time::Now();
			double deltaTime = currentTime - lastFrame;
			lastFrame = currentTime;

			if (deltaTime > 0.0)
			{
				spriteRenderer->InitFrame();

				for (auto& [id, objPtr] : gameObjects)
				{
					objPtr->Update();

					auto* sprite = objPtr->GetComponent<Sprite>();
					Transform* transform = objPtr->GetTransform();

					if (sprite)
						spriteRenderer->Draw(*sprite, *transform);
				}

				window->Update();

				//simulate processing
				//std::this_thread::sleep_for(std::chrono::microseconds(100));
			}
			double targetFrameTime = 1.0 / maxFrameRate;
			double remainingTime = targetFrameTime - deltaTime;

			if (remainingTime > 0.0)
			{
				auto sleepDuration = std::chrono::microseconds(static_cast<long long>(remainingTime * 1e6));
				std::this_thread::sleep_for(sleepDuration);
				deltaTime = targetFrameTime;
			}

			//DN_CORE_INFO("Step at {0} delta time", deltaTime);

			// Post frame operations
			Time::SetDeltaTime(deltaTime);
			ExeDestroyObjects();
		}
	}

	void Application::SetTargetFrameRate(unsigned int frameRate)
	{
		this->maxFrameRate = frameRate;
	}
	void Application::OnEvent(Event& event)
	{
		EventDispatcher dispatcher(event);

		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));
		dispatcher.Dispatch<WindowResizeEvent>(BIND_EVENT_FN(Application::OnWindowResize));

		dispatcher.DispatchByFlag(EventFlagInput, BIND_EVENT_FN(Application::OnKeyEvent));
	}

	void Application::Destroy(GameObject& gameObject)
	{
		destroyQueue.push_back(gameObject.ID());
	}

	GameObject& Application::CreateGameObject()
	{
		unsigned int id = lastGameObjectId++;
		auto obj = std::make_unique<GameObject>(id);
		auto& ref = *obj;

		gameObjects.emplace(id, std::move(obj));

		DN_CORE_INFO("Created GameObject {0}", id);

		return ref;
	}

	void Application::ExeDestroyObjects()
	{
		for (auto id : destroyQueue)
		{ 
			gameObjects.erase(id);
			DN_CORE_INFO("Destroyed GameObject {0}", id);
		}
		
		destroyQueue.clear();
	}

	bool Application::OnWindowClose(WindowCloseEvent& event)
	{
		DN_CORE_TRACE(event.ToString());
		isRunning = false;
		return true;
	}

	bool Application::OnWindowResize(WindowResizeEvent& event)
	{
		spriteRenderer->SetProjection(event.GetWidth(), event.GetHeight());

		return true;
	}

	bool Application::OnKeyEvent(Event& event)
	{
		//DN_CORE_TRACE(event.ToString());
		return true;
	}
}
