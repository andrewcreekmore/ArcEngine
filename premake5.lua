workspace "ArcEngine"
	architecture "x64"
	startproject "ArcApp"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

includedir = {}
includedir["GLFW"] = "ArcEngine/vendor/GLFW/include"
includedir["Glad"] = "ArcEngine/vendor/Glad/include"
includedir["ImGui"] = "ArcEngine/vendor/ImGui" 
includedir["GLM"] = "ArcEngine/vendor/GLM" 

-- include vendor premake files (manually added)
include "ArcEngine/vendor/GLFW"
include "ArcEngine/vendor/Glad"
include "ArcEngine/vendor/ImGui"

project "ArcEngine"
	location "ArcEngine"
	kind "StaticLib"
	language "C++"
	cppdialect "C++20"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "ArcEnginePCH.h"
	pchsource "ArcEngine/src/ArcEnginePCH.cpp"

	files
	{
		"%{prj.name}/src/**.h", 
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/GLM/glm/**.hpp",
		"%{prj.name}/vendor/GLM/glm/**.inl"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{includedir.GLFW}",
		"%{includedir.Glad}",
		"%{includedir.ImGui}",
		"%{includedir.GLM}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"
		      
		defines 
		{ 
			"ARC_PLATFORM_WINDOWS",
			"ARC_BUILD_DLL",
			"GLFW_INCLUDE_NONE" -- don't include openGL headers when including GLFW (already incl. in Glad)
		}
		

   filter "configurations:Debug"
      defines { "ARC_DEBUG" }
      runtime "Debug"
      symbols "on"

   filter "configurations:Release"
      defines { "ARC_RELEASE" }
      runtime "Release"
      optimize "on"

   filter "configurations:Dist"
      defines { "ARC_DIST" }
      runtime "Release"
      optimize "on"


project "ArcApp"
	location "ArcApp"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h", 
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"ArcEngine/vendor/spdlog/include",
		"ArcEngine/src",
		"%{includedir.GLM}",
		"ArcEngine/vendor"
	}

	links
	{ "ArcEngine" }

	filter "system:windows"
		systemversion "latest"

		defines 
		{ "ARC_PLATFORM_WINDOWS" }

	filter "configurations:Debug"
		defines { "ARC_DEBUG" }
		runtime "Debug"
		symbols "on"

   filter "configurations:Release"
		defines { "ARC_RELEASE" }
		runtime "Release"
		optimize "on"

   filter "configurations:Dist"
		defines { "ARC_DIST" }
		runtime "Release"
		optimize "on"
