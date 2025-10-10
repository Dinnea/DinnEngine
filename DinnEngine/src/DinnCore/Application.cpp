#include "dnpch.h"
#include "Application.h"
#include "glfw_glad.h"
#include "Rendering/SpriteRenderer.h"
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

		window = std::unique_ptr<Window>(Window::Create());
		window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));

		spriteRenderer = std::make_unique<SpriteRenderer>();
		spriteRenderer->SetProjection(window->GetWidth(), window->GetHeight());
	}

	Application::~Application()
	{
		instance = nullptr;
	}

	void Application::Run()
	{
		isRunning = true;

		Sprite sprite;
		sprite.position = glm::vec2(600, 500);
		sprite.scale = glm::vec2(20, 20);

		Sprite sprite2;
		sprite2.position = glm::vec2(150.0f, 150.0f);
		sprite2.angle = 45;
		sprite2.scale = glm::vec2(100.0f, 100.0f);

		Sprite* arr[2] = { &sprite, &sprite2 };
		

		while (isRunning)
		{

			double currentTime = Time::Now();
			double deltaTime = currentTime - lastFrame;
			lastFrame = currentTime;

			if (deltaTime > 0.0)
			{
				spriteRenderer->InitFrame();
				for each(Sprite* var in arr)
					spriteRenderer->Draw(*var);
				

				window->Update();


				//simulate processing
				//std::this_thread::sleep_for(std::chrono::microseconds(100));
				// TODO: update objects
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
			Time::SetDeltaTime(deltaTime);
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
	}

	bool Application::OnWindowClose(WindowCloseEvent& event)
	{
		isRunning = false;
		return true;
	}
	bool Application::OnWindowResize(WindowResizeEvent& event)
	{
		spriteRenderer->SetProjection(event.GetWidth(), event.GetHeight());

		return true;
	}
}
