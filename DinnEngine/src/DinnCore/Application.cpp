#include "dnpch.h"

#include "Application.h"
#include "Events/WindowEvent.h"

namespace Dinn
{
	Application::Application()
	{
		isRunning = false;
		maxFrameRate = 60;
		lastFrame = Time::Now();

		window = std::unique_ptr<Window>(Window::Create());

		window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
	}

	Application::~Application()
	{
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
				glClearColor(0, 1, 1, 1);
				glClear(GL_COLOR_BUFFER_BIT);

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
			DN_CORE_INFO("Step at {0} delta time", deltaTime);
			Time::SetDeltaTime(deltaTime);
		}
	}
	void Application::SetTargetFrameRate(unsigned int frameRate)
	{
		this->maxFrameRate = frameRate;
	}
	void Application::OnEvent(Event& event)
	{
		DN_CORE_INFO("{0}", event.ToString());
	}
}
