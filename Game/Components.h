#pragma once
#ifndef COMPONENTS_H_
#define COMPONENTS_H_

#include <cstdint>
#include <glm/glm.hpp>


struct TransformComponent
{
    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 size;
};

struct AnimationComponent
{
    int32_t cur_frame{};
    int32_t fps{};
    int32_t frame_ctr{};
    int32_t max_frame{};
    bool loop{ 1 };
    bool is_stopped{ 0 };
};

#endif /* COMPONENTS_H_ */