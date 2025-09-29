#include "dnpch.h"
#include "Application.h"
#include "glfw_glad.h"
#include "Rendering/TestRenderer.h"

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
	}

	Application::~Application()
	{
		instance = nullptr;
	}

	void Application::Run()
	{
		isRunning = true;

		TestRenderer test;

		while (isRunning)
		{

			double currentTime = Time::Now();
			double deltaTime = currentTime - lastFrame;
			lastFrame = currentTime;

			if (deltaTime > 0.0)
			{
				test.Draw(0, 0);

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

		//DN_CORE_TRACE("{0}", event.ToString());
	}

	bool Application::OnWindowClose(WindowCloseEvent& event)
	{
		isRunning = false;
		return true;
	}
}
