#pragma once
#ifndef RENDERER_H_
#define RENDERER_H_

#include <polos/context/texture.h>
#include <polos/context/vao.h>

#include "Components.h"

namespace constants
{
    extern const glm::mat4 k_Projection;
}

void InitializeRenderer();
void RenderTexture(pl::Texture const& texture, TransformComponent const& transform);

#endif /* RENDERER_H_ */