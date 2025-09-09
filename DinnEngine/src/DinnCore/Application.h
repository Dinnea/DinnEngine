#pragma once
#include "Core.h"

namespace Dinn
{
	class DINN_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in client
	Application* CreateApplication();
}

