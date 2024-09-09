#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "Renderer.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Shader.h"
#include "Texture.h"
#include "Core.h"
//#include "Input.h"
#include "SceneManager.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include <imgui/imgui_impl_opengl3.h>

#include "tests/TestClearColor.h"
#include "tests/TestTexture2D.h"

#include "game/Player.h"

#define FULLSCREEN 0

const char* getGLSLVer();


int Core::CheesyInit(void)
{
    
    /* Initialize the library */
    if (!glfwInit())
        return -1;

    // Create a window on the specified monitor
    GLFWwindow* window = glfwCreateWindow(1280, 720, "OpenGL aa", NULL, NULL);
    GLFWmonitor* monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode* videoMode = glfwGetVideoMode(monitor);
    if (FULLSCREEN != 0) { 
        glfwSetWindowMonitor(window, monitor, 0, 0, videoMode->width, videoMode->height, videoMode->refreshRate);
    }
    
    if (!window)

    {
        glfwTerminate();
        return -1;
    }


    /* Make the window's context current */
    glfwMakeContextCurrent(window);
  //  glfwSetKeyCallback(window, Input::keyCallback); BORKED

    auto glewStatus = glewInit();
    if (glewStatus != GLEW_OK) {
        std::cout << "Error initialising glew!" << "\n";
        return 1;
    }

    std::cout << glGetString(GL_VERSION) << "\n";
    {

        GLCall(glEnable(GL_BLEND));
        GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

      

       Renderer renderer;

       ImGui::CreateContext();
       ImGui_ImplGlfw_InitForOpenGL(window, true);
       ImGui_ImplOpenGL3_Init(getGLSLVer()); //getGLSLVer code below
       ImGui::StyleColorsDark();
       ImGuiIO& io = ImGui::GetIO(); (void)io;
       
       //GLCall(glEnable(GL_DEPTH_TEST));
        Player minge(window);

        /* Loop until the user closes the window */
       while (!glfwWindowShouldClose(window))
       {
           GLCall(glClearColor(0.0f, 0.0f, 0.0f, 1.0f));
           GLCall(glClear(GL_COLOR_BUFFER_BIT)); // | GL_DEPTH_BUFFER_BIT
           renderer.Clear();

           ImGui_ImplOpenGL3_NewFrame();
           ImGui_ImplGlfw_NewFrame();
           ImGui::NewFrame();

           

           SceneManager::SceneManagerInstance->TickObjects();

            ImGui::Render();
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

            /* Swap front and back buffers */
            glfwSwapBuffers(window);

            /* Poll for and process events */
            glfwPollEvents();
        }

    }
 

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwTerminate();
    return 0;
}

const char* getGLSLVer() {
    // Decide GL+GLSL versions
#if defined(IMGUI_IMPL_OPENGL_ES2)
    // GL ES 2.0 + GLSL 100
    const char* glsl_version = "#version 100";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
#elif defined(__APPLE__)
    // GL 3.2 + GLSL 150
    const char* glsl_version = "#version 150";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // Required on Mac
#else
    // GL 3.0 + GLSL 130
    const char* glsl_version = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // 3.0+ only
#endif
    return glsl_version;
}
