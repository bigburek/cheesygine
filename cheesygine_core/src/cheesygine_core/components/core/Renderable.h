#pragma once
#include <string>
#include <memory>
#include "../../VertexBuffer.h"
#include "../../Texture.h"
#include "../../VertexArray.h"

class Renderable {
public:
    virtual ~Renderable() {}
    std::unique_ptr <VertexArray> m_VAO;
    std::unique_ptr <IndexBuffer> m_IndexBuffer;
    std::unique_ptr <Shader> m_Shader;
    std::unique_ptr <VertexBuffer> m_VertexBuffer;
    glm::mat4 m_Proj, m_View, m_Model;
    std::unique_ptr <Texture> m_Texture;
};
