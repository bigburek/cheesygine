project "cheesygine_core"
   kind "StaticLib"
   language "C++"
   cppdialect "C++20"
   staticruntime "on"

   targetdir ("../Binaries/" .. OutputDir .. "/%{prj.name}")
   objdir ("../Binaries/Intermediates/" .. OutputDir .. "/%{prj.name}")

   files { "src/**.h", "src/**.cpp", "../libs/**.h", "../libs/**.cpp"  }

   includedirs {
      "src/cheesygine_core",
      "vendor",
      "../vendor/glfw/include/",
      "../vendor/glew/include/",
      "../libs"
   }

   links { "glfw", "glew", "GL"}

   filter "system:windows"
      systemversion "latest"
      defines { "WINDOWS", "GLEW_STATIC" }

   filter "configurations:Debug"
      defines { "DEBUG" }
      runtime "Debug"
      symbols "on"

   filter "configurations:Release"
      defines { "NDEBUG" }
      runtime "Release"
      optimize "on"

   filter "configurations:Dist"
      defines { "NDEBUG" }
      runtime "Release"
      optimize "on"

