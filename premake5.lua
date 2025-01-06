 workspace "Xi"
 architecture "x64"

 configurations { "Debug",
		"Release",
		"Dist"}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

 project "Xi"
	location "Xi"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files{"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
		}

	includedirs {
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/src"
		--trouble me a lot
	}
filter "system:windows"
	cppdialect "C++17"
	staticruntime "On"
	systemversion "latest"
    defines {
		"X_BUILD_DLL",
		"X_WINDOWS"
	}
	buildoptions { "/utf-8" } 

filter "configurations:Debug"
	defines { "DEBUG" }
	symbols "On"

filter "configurations:Release"
	defines { "Release" }
	optimize "On"

filter "configurations:Dist"
	defines { "Dist" }
	optimize "On"

postbuildcommands {  
    "{MKDIR} ../bin/" .. outputdir .. "/Sandbox",  --
    "{COPYFILE} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox"  
}
	
project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files{"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
		}

	includedirs {
		"Xi/vendor/spdlog/include",
		"Xi/src",
		"Xi/src/X"
	--too trouble
	}

	links {
		"Xi"
	}

filter "system:windows"
	cppdialect "C++17"
	staticruntime "On"
	systemversion "latest"
    defines {
		"X_WINDOWS"
	}

	buildoptions { "/utf-8" } 
filter "configurations:Debug"
	defines { "DEBUG" }
	symbols "On"

filter "configurations:Release"
     defines { "Release" }
	optimize "On"

filter "configurations:Dist"
	defines { "Dist" }
	optimize "On"