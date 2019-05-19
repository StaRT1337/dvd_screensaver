workspace "dvd"
    location "./build"
    objdir "%{wks.location}/obj"
    targetdir "%{wks.location}/bin/%{cfg.platform}/%{cfg.buildcfg}"

    configurations {
        "Debug",
        "Release",
    }

    platforms {"x64"}
    architecture "x64"

    systemversion "latest"
    symbols "On"
    editandcontinue "Off"
    warnings "Extra"

    flags {
		"NoIncrementalLink",
		"NoMinimalRebuild",
		"MultiProcessorCompile",
		"No64BitChecks"
	}

	filter "action:vs*"
		buildoptions "/std:c++17"
		defines {
			"_WINDOWS",
			"WIN32",
		}

	filter "action:gmake*"
		cppdialect "C++17"
		buildoptions "-std=c++17"
		defines {
			"_LINUX",
        }
        
    filter "Release"
        optimize "Full"
        defines {"NODEBUG"}
        flags {"FatalCompileWarnings"}
    
    filter "Debug"
        optimize "Debug"
        defines {"DEBUG", "_DEBUG",}

    filter {}

    startproject "dvd"
    project "dvd"
        kind "ConsoleApp"
        language "C++"

        pchheader "stdinc.hpp"
        pchsource "./src/stdinc.cpp"

        files {
            "./src/**.cpp",
            "./src/**.hpp",
        }

        includedirs {
            "./src",
            "%{prj.location}/src",
            "./deps/include/**",
        }

        filter "architecture:x86"
            libdirs {"./deps/x86/**"}
        filter "architecture:x64"
            libdirs {"./deps/x64/**"}
        
        filter {}
    
        links {
            "raylib_static",
            "WinMM",
        }

