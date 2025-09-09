workspace "DinnEngine"
    architecture "x64"
    startproject "ExampleGame"
    configurations
    {
        "Debug",
        "Release"
    }
    buildoptions { "/utf-8" }

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "DinnEngine"
    location "DinnEngine"
    kind "SharedLib"
    language "C++"
    targetdir ("bin/" .. outputdir .."/%{prj.name}")
    objdir("bin-int/" .. outputdir .."/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "DN_PLATFORM_WINDOWS",
            "DN_BUILD_DLL"
        }

        postbuildcommands
        {
            "{COPYFILE} %{cfg.buildtarget.abspath} ../bin/" .. outputdir .."/ExampleGame/%{prj.name}.dll"
        }

    filter "configurations:Debug"
        defines "DN_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "DN_DEBUG"
        optimize "On"

project "ExampleGame"
    location "ExampleGame"
    kind "ConsoleApp"
    language "C++"
    targetdir ("bin/" .. outputdir .."/%{prj.name}")
    objdir("bin-int/" .. outputdir .."/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "DinnEngine/vendor/spdlog/include",
        "DinnEngine/src"
    }

    links 
    {
        "DinnEngine"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "DN_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "DN_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "DN_DEBUG"
        optimize "On"
