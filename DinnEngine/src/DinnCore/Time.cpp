#include "Time.h"
namespace Dinn
{
	double Time::deltaTime = 0.0;
	double Time::applicationStarted = Time::Now();

	double Time::Now()
	{
		return static_cast<double>(std::chrono::duration_cast<std::chrono::milliseconds>(
			std::chrono::high_resolution_clock::now().time_since_epoch()).count());
	}

	double Time::Elapsed()
	{
		return Now() - applicationStarted;
	}

	double Time::DeltaTime()
	{
		return deltaTime;
	}

	void Time::SetDeltaTime(const double deltaTime)
	{
		Time::deltaTime = deltaTime;
	}
}
