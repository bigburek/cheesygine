workspace "cheesygine"
   architecture "x64"
   configurations { "Debug", "Release", "Dist" }
   startproject "cheesygine_runtime"

   -- Workspace-wide build options for MSVC
   filter "system:windows"
      buildoptions { "/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus" }

OutputDir = "%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}"

group "core"
	include "cheesygine_core/build_core.lua"
group ""

include "cheesygine_runtime/build_runtime.lua"

include "vendor/build_glfw.lua"
include "vendor/build_glew.lua"