#pragma once
#include <glm/glm.hpp>
#include <memory>
#include "components/core/Renderable.h"

class GameObject {
public:
	GameObject();
    virtual ~GameObject();
    virtual void OnStart()  {};
    virtual void OnUpdate()  {};
    std::unique_ptr<Renderable> m_Renderable;
public:
	glm::vec3 m_Translation;

    void setRenderable(std::unique_ptr<Renderable> renderable) {
        this->m_Renderable = std::move(renderable);
    }
};
