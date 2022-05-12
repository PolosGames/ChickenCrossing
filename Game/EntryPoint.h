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
    Game m_Game;
};

#endif /* ENTRYPOINT_H_ */