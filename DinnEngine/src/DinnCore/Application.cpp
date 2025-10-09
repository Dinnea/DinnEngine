#include "dnpch.h"
#include "Application.h"
#include "glfw_glad.h"
#include "Rendering/Renderer2D.h"

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

		renderer = std::make_unique<Renderer2D>();
		renderer->SetProjection(window->GetWidth(), window->GetHeight());
	}

	Application::~Application()
	{
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
				renderer->Draw();

				window->Update();


				//simulate processing
				//std::this_thread::sleep_for(std::chrono::microseconds(100));
				// TODO: process input
				// TODO: update objects
				// TODO: render
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
		renderer->SetProjection(event.GetWidth(), event.GetHeight());

		return true;
	}
}
