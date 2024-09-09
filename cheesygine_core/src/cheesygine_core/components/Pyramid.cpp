#include "Pyramid.h"

#include <GL/glew.h>
#include "GLMacros.h"

#include <glm/glm.hpp>
#include "glm/gtc/matrix_transform.hpp"

#include <libgen.h>         // dirname
#include <unistd.h>         // readlink
#include <linux/limits.h>   // PATH_MAX
#include <string.h>

Pyramid::Pyramid(const std::string& imagepath, glm::vec3 abcd) : m_ImagePath(imagepath), abc(abcd)
{
    m_Proj = glm::perspective(glm::radians(45.0f), (float)(1280/720), 0.1f, 10000.0f);
    m_View = (glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, -100.0f, -300.0f)));



    float positions[] = {
        // Base of the pyramid
        -100.0f,  0.0f,    100.0f,    0.0f,  0.0f,
        -100.0f,  0.0f, -100.0f,       1.0f,   0.0f,
        100.0f, 0.0f, -100.0f,      1.0f,   1.0f,
        100.0f, 0.0f, 100.0f,      0.0f,   1.0f,

        // Top of the pyramid
        0.0f, 160.0f, 0.0f, 0.5f, 1.0f
    };

    unsigned int indecies[] = {
        // Base of the pyramid
        0, 1, 2,
        2, 3, 0,

        // Sides of the pyramid
        0, 1, 4,
        1, 2, 4,
        2, 3, 4,
        3, 0, 4
    };

        

    GLCall(glEnable(GL_BLEND));
    GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));


    m_VAO = std::make_unique<VertexArray>();

    m_VertexBuffer = std::make_unique<VertexBuffer>(positions, 5 * 5 * sizeof(float));

    VertexBufferLayout layout;
    layout.Push<float>(3);
    
    layout.Push<float>(2);
    m_VAO->AddBuffer(*m_VertexBuffer, layout);

    m_IndexBuffer = std::make_unique<IndexBuffer>(indecies, 25);

    char path[PATH_MAX];
    char result[PATH_MAX];
    ssize_t count = readlink("/proc/self/exe", result, PATH_MAX);

    if (count != -1) {
        result[count] = '\0'; // Null-terminate the string
        strcpy(path, dirname(result));
        printf("The directory of the executable is: %s\n", path);
    } else {
        perror("readlink");
    }
    std::string mingela = std::string(path) + "/res/shaders/Basic.shader";

    m_Shader = std::make_unique<Shader>(mingela);
    m_Shader->Bind();
    m_Shader->SetUnifrom1i("u_Texture", 0);
    // shader.SetUniform4f("u_Color", 0.2f, 0.3f, 0.8f, 0.1f);

    m_Texture = std::make_unique<Texture>(m_ImagePath);

};


Pyramid::~Pyramid()
{
}
