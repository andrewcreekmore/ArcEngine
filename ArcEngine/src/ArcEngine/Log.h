#pragma once

#include "Core.h"

#define GLM_ENABLE_EXPERIMENTAL
#include "glm/gtx/string_cast.hpp"

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

/*
===========================================================================
Log: wrapper for spdlog
- defines static functions that forward args to spdlog
- defines global macros for core (ArcEngine) and client (ArcApp) logging
===========================================================================
*/

namespace ArcEngine
{
	class ARCENGINE_API Log
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

//---------------------------// 
// GLM logging

template<typename OStream, glm::length_t L, typename T, glm::qualifier Q>
inline OStream& operator<<(OStream& os, const glm::vec<L, T, Q>& vector)
{
	return os << glm::to_string(vector);
}

template<typename OStream, glm::length_t C, glm::length_t R, typename T, glm::qualifier Q>
inline OStream& operator<<(OStream& os, const glm::mat<C, R, T, Q>& matrix)
{
	return os << glm::to_string(matrix);
}

template<typename OStream, typename T, glm::qualifier Q>
inline OStream& operator<<(OStream& os, glm::qua<T, Q> quaternion)
{
	return os << glm::to_string(quaternion);
}

//---------------------------// 

// core log macros
#define ARC_CORE_TRACE(...)     ::ArcEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ARC_CORE_INFO(...)      ::ArcEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ARC_CORE_WARN(...)      ::ArcEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ARC_CORE_ERROR(...)     ::ArcEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ARC_CORE_CRITICAL(...)  ::ArcEngine::Log::GetCoreLogger()->critical(__VA_ARGS__)

// client app log macros
#define ARC_TRACE(...)          ::ArcEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ARC_INFO(...)           ::ArcEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define ARC_WARN(...)           ::ArcEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ARC_ERROR(...)          ::ArcEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define ARC_CRITICAL(...)       ::ArcEngine::Log::GetClientLogger()->critical(__VA_ARGS__)