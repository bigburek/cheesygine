#include "Player.h"
#include <libgen.h>         // dirname
#include <unistd.h>         // readlink
#include <linux/limits.h>   // PATH_MAX
#include <string.h>


Player::Player(GLFWwindow* winodw) : m_Window(winodw) {
    m_Translation = glm::vec3(0, 0, -200);
    glm::vec3 deez(100, 100, 100);
    
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
    std::string mingela = std::string(path) + "/res/textures/mingela.png";
    
    setRenderable(std::make_unique<Pyramid>(mingela, deez));
}

void Player::OnUpdate()
{
    if (glfwGetKey(m_Window, GLFW_KEY_D)) {
        m_Translation.x += 1;
    }
    if (glfwGetKey(m_Window, GLFW_KEY_A)) {
        m_Translation.x -= 1;
    }
    if (glfwGetKey(m_Window, GLFW_KEY_W)) {
        m_Translation.z += 20;
    }
    if (glfwGetKey(m_Window, GLFW_KEY_S)) {
        m_Translation.z -= 20;
    } //PROBLEM CANT USE IO.DELTATIME, MAKE GAMEOBJECT GET

}

void Player::OnStart() {

}
