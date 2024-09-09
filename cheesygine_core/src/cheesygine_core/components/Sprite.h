#pragma once
#include <iostream>
#include <string>
#include <memory>
#include "Texture.h"
#include "core/Renderable.h"

//#include "GameObject.h"

class Sprite : public Renderable {
public:
	Sprite(const std::string& imagepath, glm::vec3 abcd);
	void OnRender();

	~Sprite();
public:
    std::string m_ImagePath;
	glm::vec3 abc;
	//GameObject* m_ParentObject;
};
