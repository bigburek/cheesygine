#include "GameObject.h"
#include "SceneManager.h"
#include <iostream>

GameObject::GameObject() : m_Renderable(nullptr)
{
	std::cout << "Registering object!\n";
	SceneManager::getInstance()->RegisterObject(this);
}

GameObject::~GameObject()
{
	SceneManager::getInstance()->RemoveObject(this);
}
