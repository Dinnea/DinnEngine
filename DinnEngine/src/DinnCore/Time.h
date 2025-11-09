#pragma once
#include "Core.h"
#include <chrono>

namespace Dinn
{
	class DINN_API Time
	{
	public:
		/// <returns> Time since epoch in seconds</returns>
		static double Now();
		/// <returns> Time since application started in seconds</returns>
		static double Elapsed();

		/// <returns>Time since last frame</returns>
		static double DeltaTime();

	private:
		static void SetDeltaTime(const double deltaTime);

		static double deltaTime;
		static double applicationStarted;

		friend class Application;
	};

}
