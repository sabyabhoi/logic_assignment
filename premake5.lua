workspace "proParser"
   configurations { "Debug", "Release" }
   
project "proParser"
	kind "ConsoleApp"
	language "C++"
	targetdir "bin/%{cfg.buildcfg}"

	includedirs {
		"include",
	}
	files {
		"src/**.cpp",
	}

	filter "configurations:Debug"
		defines { "DEBUG" }
		symbols "On"

	filter "configurations:Release"
		defines { "NDEBUG" }
		optimize "On"
