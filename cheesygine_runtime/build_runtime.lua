project "cheesygine_runtime"
   kind "ConsoleApp"
   language "C++"
   cppdialect "C++20"
   staticruntime "off"

   targetdir ("../Binaries/" .. OutputDir .. "/%{prj.name}")
   objdir ("../Binaries/Intermediates/" .. OutputDir .. "/%{prj.name}")

   files { "src/**.h", "src/**.cpp", "../libs/**.h", "../libs/**.cpp"  }

   includedirs {
      "src/cheesygine_runtime",
      "../cheesygine_core/src",
      "../libs"
   }

   links {
      "cheesygine_core", "glfw", "glew", "GL"
   }

   filter "system:windows"
      systemversion "latest"
      defines { "WINDOWS" }

   filter "configurations:Debug"
      defines { "DEBUG" }
      runtime "Debug"
      symbols "On"

   filter "configurations:Release"
      defines { "RELEASE" }
      runtime "Release"
      optimize "On"
      symbols "On"

   filter "configurations:Dist"
      defines { "DIST" }
      runtime "Release"
      optimize "On"
      symbols "Off"
