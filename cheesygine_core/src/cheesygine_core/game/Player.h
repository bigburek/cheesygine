#pragma once
#include "../GameObject.h"
#include "../components/Pyramid.h"

#include <GLFW/glfw3.h>

class Player : public GameObject {
public:
	Player(GLFWwindow* window);
	void OnUpdate() override;
    void OnStart() override;
private:
	GLFWwindow* m_Window;
};
