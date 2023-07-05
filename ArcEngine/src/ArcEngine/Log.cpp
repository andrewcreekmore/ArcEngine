#include "ArcEnginePCH.h"
#include "Log.h"
#include <spdlog/sinks/stdout_color_sinks.h>

/*
===========================================================================
Log: wrapper for spdlog
- defines static functions that forward args to spdlog
- defines global macros for core (ArcEngine) and client (ArcApp) logging
===========================================================================
*/

namespace ArcEngine
{
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init()
	{
		// formatting: timestamp, name of logger, message content
		spdlog::set_pattern("%^[$T] %n: %v%$");

		// set logger names and their log reporting levels
		s_CoreLogger = spdlog::stdout_color_mt("ARCENGINE");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("APP");
		s_ClientLogger->set_level(spdlog::level::trace);
	}
}