#pragma once
#ifndef GMATH_H_
#define GMATH_H_

#include <glm/glm.hpp>

namespace Math
{
    constexpr inline glm::mat4 Ortho(float left, float right, float bottom, float top, float zNear, float zFar)
    {
        float x0 = static_cast<float>(2) / (right - left);
        float y1 = static_cast<float>(2) / (top - bottom);
        float z2 = -static_cast<float>(2) / (zFar - zNear);
        float x3 = -(right + left) / (right - left);
        float y3 = -(top + bottom) / (top - bottom);
        float z3 = -(zFar + zNear) / (zFar - zNear);
        return glm::mat4{
            x0,   0.0f, 0.0f, 0.0f,
            0.0f, y1,   0.0f, 0.0f,
            0.0f, 0.0f, z2,   0.0f,
            x3,   y3,   z3,   1.0f
        };
    }
}

#endif /* GMATH_H_ */