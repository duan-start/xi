#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"
namespace X
{
	//inner class ,declaration ,no memory
	//outer class ,definition ,memory
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;
	

	void Log::Init() {


		spdlog::set_pattern("%^[%T] %n: %v%$");
		//ues the different color for different consele
		//in the futrue ,may be wo can changed the color (format strings,or maybe not)
		s_ClientLogger = spdlog::stdout_color_mt("X");

		//set the level of log, trace is the highest level
		//meaning with all?
		s_ClientLogger->set_level(spdlog::level::trace);


		s_CoreLogger = spdlog::stdout_color_mt("APP");
		s_CoreLogger->set_level(spdlog::level::trace);
	}
}
