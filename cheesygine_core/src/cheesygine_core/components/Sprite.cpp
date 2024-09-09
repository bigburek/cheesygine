#include "Sprite.h"

#include <GL/glew.h>
#include "GLMacros.h"

#include <glm/glm.hpp>
#include "glm/gtc/matrix_transform.hpp"


#include <libgen.h>         // dirname
#include <unistd.h>         // readlink
#include <linux/limits.h>   // PATH_MAX
#include <string.h>

Sprite::Sprite(const std::string& imagepath, glm::vec3 abcd) : m_ImagePath(imagepath), abc(abcd)
{
    m_Proj = (glm::ortho(0.0f, 1280.0f, 0.0f, 720.0f, -1.0f, 1.0f));
    m_View = (glm::translate(glm::mat4(1.0f), glm::vec3(-100, 0, 0)));

    float positions[] = {
    200.0f,200.0f, 0.0f, 0.0f,
    500.0f, 200.0f, 1.0f, 0.0f,
    500.0f, 500.0f, 1.0f, 1.0f,
    200.0f, 500.0f, 0.0f, 1.0f
    };

    //DONT FORGGER TO CENTER PICTUR PLS

    unsigned int indecies[] = {
        0, 1, 2,
        2, 3, 0
    };
        

    GLCall(glEnable(GL_BLEND));
    GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));


    m_VAO = std::make_unique<VertexArray>();

    m_VertexBuffer = std::make_unique<VertexBuffer>(positions, 4 * 4 * sizeof(float));

    VertexBufferLayout layout;
    layout.Push<float>(2);
    layout.Push<float>(2);
    m_VAO->AddBuffer(*m_VertexBuffer, layout);

    m_IndexBuffer = std::make_unique<IndexBuffer>(indecies, 6);

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


Sprite::~Sprite()
{
}
