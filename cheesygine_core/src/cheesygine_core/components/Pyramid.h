#pragma once
#include <iostream>
#include <string>
#include <memory>
#include "Texture.h"
#include "core/Renderable.h"

//#include "GameObject.h"

class Pyramid : public Renderable {
public:
	Pyramid(const std::string& imagepath, glm::vec3 abcd);
	void OnRender();

	~Pyramid();
public:
    std::string m_ImagePath;
	glm::vec3 abc;
	//GameObject* m_ParentObject;
};
