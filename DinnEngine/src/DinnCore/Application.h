#pragma once
#include "Core.h"
#include "Time.h"
#include <chrono>
#include <thread>
#include "Window.h"
#include "GLFW/glfw3.h"
#include "Events/WindowEvent.h"

namespace Dinn
{
	class DINN_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		void SetTargetFrameRate(unsigned int frameRate);

		void OnEvent(Event& event);

	private:
		bool OnWindowClose(WindowCloseEvent& event);

		bool isRunning;
		unsigned int maxFrameRate;
		double lastFrame;

		std::unique_ptr<Window> window;
	};

	// To be defined in client
	Application* CreateApplication();
}

