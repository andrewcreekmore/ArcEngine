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
	kind "SharedLib"
	language "C++"

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
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"
		      
	defines 
	{ 
		"ARC_PLATFORM_WINDOWS",
		"ARC_BUILD_DLL",
		"GLFW_INCLUDE_NONE" -- don't include openGL headers when including GLFW (already incl. in Glad)
	}

	postbuildcommands
	{ ("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/ArcApp\"") }
				

   filter "configurations:Debug"
      defines { "ARC_DEBUG" }
      runtime "Debug"
	  buildoptions "/MDd"
      symbols "On"

   filter "configurations:Release"
      defines { "ARC_RELEASE" }
      runtime "Release"
	  buildoptions "/MD"
      optimize "On"
      symbols "On"

   filter "configurations:Dist"
      defines { "ARC_DIST" }
      runtime "Release"
	  buildoptions "/MD"
      optimize "On"
      symbols "Off"


project "ArcApp"
	location "ArcApp"
	kind "ConsoleApp"
	language "C++"

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
		"%{includedir.GLM}"
	}

	links
	{ "ArcEngine" }

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

	defines 
	{ "ARC_PLATFORM_WINDOWS" }

	filter "configurations:Debug"
		defines { "ARC_DEBUG" }
		runtime "Debug"
		buildoptions "/MDd"
		symbols "On"

   filter "configurations:Release"
		defines { "ARC_RELEASE" }
		runtime "Release"
		buildoptions "/MD"
		optimize "On"
		symbols "On"

   filter "configurations:Dist"
		defines { "ARC_DIST" }
		runtime "Release"
		buildoptions "/MD"
		optimize "On"
		symbols "Off"