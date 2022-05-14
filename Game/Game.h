#pragma once
#ifndef GAME_H_
#define GAME_H_

#include "Ecs/Scene.h"

class Game
{
public:
    Game();

    void Update(float delta_time);
    static Scene& GetCurentScene();
private:
    int32_t m_CurrentScene{};
    Scene   m_Levels[1];

    Entity  chicken;
    TransformComponent* transform;
    AnimationComponent* animation;

private:
    friend class EntryPoint;
    static Game* s_Instance;
};

#endif /* GAME_H_ */