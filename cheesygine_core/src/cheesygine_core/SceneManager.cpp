#include "SceneManager.h"
#include "Renderer.h"
#include <glm/glm.hpp>
#include "components/core/Renderable.h"
#include "glm/gtc/matrix_transform.hpp"
#include <iostream>

void SceneManager::RegisterObject(GameObject* gameobject)
{
	m_SceneObjects.push_back(gameobject);
}

void SceneManager::RemoveObject(GameObject* gameobject) {
    //this->m_SceneObjects.erase(std::remove(m_SceneObjects.begin(), m_SceneObjects.end(), gameobject), m_SceneObjects.end());
}
float rotation = 0.0f;
void SceneManager::TickObjects() {
	if (m_SceneObjects.empty()) return;

    for (GameObject* obj : m_SceneObjects) {
        obj->OnUpdate();
        if (obj->m_Renderable != nullptr) {
            obj->m_Renderable->m_Texture->Bind();
            glm::mat4 model = glm::translate(glm::mat4(1.0f), obj->m_Translation);
            glm::mat4 mvp = obj->m_Renderable->m_Proj * obj->m_Renderable->m_View * model;
            obj->m_Renderable->m_Shader->Bind();
            obj->m_Renderable->m_Shader->SetUniformMat4f("u_MVP", mvp);
            renderer.Draw(*obj->m_Renderable->m_VAO, *obj->m_Renderable->m_IndexBuffer, *obj->m_Renderable->m_Shader);
        }
	}
}

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
	m_SceneObjects.clear();
	delete SceneManagerInstance;
}

SceneManager* SceneManager::SceneManagerInstance = NULL;
