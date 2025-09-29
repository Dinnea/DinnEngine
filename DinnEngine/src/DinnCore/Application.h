#pragma once
#include "Core.h"
#include "Events/WindowEvent.h"
#include "Time.h"
#include "Window.h"
#include <chrono>
#include <thread>

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

		static Application& Get() noexcept { return *instance; }
		Window& GetWindow() noexcept { return *window; }

	private:
		bool OnWindowClose(WindowCloseEvent& event);

		bool isRunning;
		unsigned int maxFrameRate;
		double lastFrame;

		static Application* instance;
		std::unique_ptr<Window> window;
	};

	// To be defined in client
	Application* CreateApplication();
}
