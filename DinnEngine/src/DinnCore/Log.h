#pragma once
#include "Core.h"
#include "memory.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Dinn
{
	class DINN_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

//Core log macros
#define DN_CORE_TRACE(...)	::Dinn::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define DN_CORE_INFO(...)	::Dinn::Log::GetCoreLogger()->info(__VA_ARGS__)
#define DN_CORE_WARN(...)	::Dinn::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define DN_CORE_ERROR(...)	::Dinn::Log::GetCoreLogger()->error(__VA_ARGS__)
#define DN_CORE_FATAL(...)	::Dinn::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log macros
#define DN_TRACE(...)	::Dinn::Log::GetClientLogger()->trace(__VA_ARGS__)
#define DN_INFO(...)	::Dinn::Log::GetClientLogger()->info(__VA_ARGS__)
#define DN_WARN(...)	::Dinn::Log::GetClientLogger()->warn(__VA_ARGS__)
#define DN_ERROR(...)	::Dinn::Log::GetClientLogger()->error(__VA_ARGS__)
#define DN_FATAL(...)	::Dinn::Log::GetClientLogger()->fatal(__VA_ARGS__)



