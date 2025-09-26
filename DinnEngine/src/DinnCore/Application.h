#pragma once
#include "Core.h"
#include "Time.h"
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

	private:
		bool isRunning;
		unsigned int maxFrameRate;
		double lastFrame;
	};

	// To be defined in client
	Application* CreateApplication();
}

