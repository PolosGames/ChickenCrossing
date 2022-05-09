#pragma once
#ifndef RENDERER_H_
#define RENDERER_H_

#include <polos/context/texture.h>
#include <polos/context/vao.h>

namespace constants
{
    extern const glm::mat4 k_Projection;
}

void InitializeRenderer();
void RenderTexture(pl::Texture const& texture, glm::vec3 const& position, 
                    glm::vec2 const& dimensions = glm::vec2{0.0f}, float rotation = 0.0f);

#endif /* RENDERER_H_ */