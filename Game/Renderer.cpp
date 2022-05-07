#include "polos/polos_pch.h"

#include <polos/utils/stringid.h>
#include <glad/glad.h>

#include "GMath.h"
#include "Resources.h"

#include "Renderer.h"

constexpr glm::mat4 k_Projection{ Math::Ortho(-640.0f, 640.0f, -360.0f, 360.0f, -1.0f, 1.0f) };

static pl::Vao* s_TextureVao;

void InitializeRenderer()
{
    constexpr std::array<pl::vertex, 4> quad_vertices {
        pl::vertex{glm::vec3(-0.5f,  0.5f, 0.0f), glm::vec3(1.0f), glm::vec2{0.0f, 1.0f}, glm::vec3{1.0f}}, // Top-left
        pl::vertex{glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec3(1.0f), glm::vec2{0.0f, 0.0f}, glm::vec3{1.0f}}, // Bottom-left
        pl::vertex{glm::vec3( 0.5f, -0.5f, 0.0f), glm::vec3(1.0f), glm::vec2{1.0f, 0.0f}, glm::vec3{1.0f}}, // Bottom-right
        pl::vertex{glm::vec3( 0.5f,  0.5f, 0.0f), glm::vec3(1.0f), glm::vec2{1.0f, 1.0f}, glm::vec3{1.0f}}, // Top-right
    };

    constexpr std::array<pl::uint32, 6> quad_indices {
        0, 1, 2,
        2, 3, 0
    };

    s_TextureVao = new pl::Vao{ quad_vertices, quad_indices };
    Resources::Instance->texture_shader.Use();
    Resources::Instance->texture_shader.SetInt("u_Texture"_sid, 0);
    Resources::Instance->texture_shader.SetMat("u_Proj"_sid, k_Projection);
}

void RenderTexture(pl::Texture const& texture, glm::vec3 const& position, 
                    glm::vec2 const& dimensions, float rotation)
{
    glm::mat4 model{ 1.0 };
    
    model = glm::translate(model, glm::vec3{ position });
    model = glm::rotate(model, glm::radians(rotation), glm::vec3(0.0f, 0.0f, 1.0f));
    model = glm::scale(model, glm::vec3(dimensions, 1.0f));

    Resources::Instance->texture_shader.Use();
    Resources::Instance->texture_shader.SetMat("u_Model"_sid, model);
    
    glBindTextureUnit(0, texture.id);
    s_TextureVao->Draw();
}
