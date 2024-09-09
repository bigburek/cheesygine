#include <GL/glew.h>
#include <GLFW/glfw3.h>
#pragma once

namespace Input {
	extern bool keyPressedData[GLFW_KEY_LAST];
	extern bool mouseButtonPressedData[GLFW_MOUSE_BUTTON_LAST];
	extern float mouseX;
	extern float mouseY;
	extern float mouseScrollX;
	extern float mouseScrollY;

	void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	void mouseCallback(GLFWwindow* window, double xpos, double ypos);
	void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
	void mouseScrollCallback(GLFWwindow* window, double xoffset, double yoffset);
	void joystick_callback(int jid, int event);
	const float* getJoystickAxes();
	const unsigned char* getJoystickButtons();
	const unsigned char* getJoystickHats();

	bool isKeyDown(int key);
	bool isMouseButtonDown(int mouseButton);

};