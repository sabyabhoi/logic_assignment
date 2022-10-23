workspace "proParser"
   architecture "x64"
   configurations { "Debug",  "Profiling", "Release" }
   
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
		removefiles {"src/profiler.cpp"}
		symbols "On"

	filter "configurations:Profiling"
		defines { "DEBUG" }
		buildoptions { "-pg" }
		linkoptions { "-pg" }
		removefiles {"src/main.cpp"}
		symbols "On"
		optimize "On"

	filter "configurations:Release"
		defines { "NDEBUG" }
		removefiles {"src/profiler.cpp"}
		optimize "On"

project "proParser_test"
    kind "ConsoleApp"
	language "C++"
	targetdir "bin/test"

	includedirs {
 	    "include",
		"lib/googletest/googletest",
		"lib/googletest/googletest/include"
	}

	libdirs { "lib" }
	files {
		"src/**.cpp",
		"test/**.cpp",
		"lib/googletest/googletest/src/gtest-all.cc"
	}
	removefiles {"src/main.cpp", "src/profiler.cpp"}


