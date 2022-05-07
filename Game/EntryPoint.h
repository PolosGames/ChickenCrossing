#pragma once
#ifndef ENTRYPOINT_H_
#define ENTRYPOINT_H_

#include <polos/core/application.h>
#include <polos/context/texture.h>
#include <polos/context/vao.h>
#include <polos/context/shader.h>

class EntryPoint : public pl::Application
{
public:
    EntryPoint(pl::window_props&& props);
    ~EntryPoint();

    void Update(float delta_time);
private:
    pl::Texture                 texture;
    std::unique_ptr<pl::Vao>    vao;
    std::unique_ptr<pl::Shader> shader;
    glm::vec3 position;
    glm::vec2 size;
    float rotation;
    std::unique_ptr<pl::Camera> camera;
};

#endif /* ENTRYPOINT_H_ */