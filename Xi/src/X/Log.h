#pragma once
#include <memory.h>

#include <Core.h>
#include <spdlog/spdlog.h>
namespace X {
	class  X_API Log
	{
	public :
		inline static std::shared_ptr<spdlog::logger> &GetClientLogger() {return  s_ClientLogger;}
		inline static std::shared_ptr<spdlog::logger>&GetCoreLogger() {return  s_CoreLogger;}
		static void Init();
	private:
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
		static std::shared_ptr<spdlog::logger> s_CoreLogger;

	};

}


//core 
#define X_CORE_TRACE(...)    ::X::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define X_CORE_INFO(...)     ::X::Log::GetCoreLogger()->info(__VA_ARGS__)
#define X_CORE_WARN(...)     ::X::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define X_CORE_ERROR(...)    ::X::Log::GetCoreLogger()->error(__VA_ARGS__)

//client, but here the name is not contain client (may be the custom)
#define X_TRACE(...)         ::X::Log::GetClientLogger()->trace(__VA_ARGS__)
#define X_INFO(...)          ::X::Log::GetClientLogger()->info(__VA_ARGS__)
#define X_WARN(...)          ::X::Log::GetClientLogger()->warn(__VA_ARGS__)
#define X_ERROR(...)         ::X::Log::GetClientLogger()->error(__VA_ARGS__)


