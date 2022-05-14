#include <polos/polos_pch.h>

#include <imgui.h>
#include <polos/core/update_queue.h>

#include "Renderer.h"
#include "Resources.h"
#include "Components.h"
#include "AnimationManager.h"

#include "Game.h"

Game* Game::s_Instance;

Game::Game()
{
    UPDATE_Q_MEM_ADD_LAST(Game, Update);
    Scene& scene = m_Levels[m_CurrentScene];

    chicken = scene.NewEntity();
    
    TransformComponent t;
    t.position = { 200.0f, 200.0f, 0.0f };
    t.rotation = { 0.0f, 0.0f, 0.0f };
    t.size     = { 250.0f, 250.0f, 0.0f };
    transform = scene.Assign<TransformComponent>(chicken, std::move(t));

    AnimationComponent anim;
    anim.max_frame = 4;
    anim.fps       = 2;
    animation = scene.Assign<AnimationComponent>(chicken, std::move(anim));
}

void Game::Update(float delta_time)
{
    RenderTexture(*g_Resources->chicken_anim[0][0][animation->cur_frame], *transform);
    AnimationManager::Update(delta_time);
}

Scene& Game::GetCurentScene()
{
    return(s_Instance->m_Levels[s_Instance->m_CurrentScene]);
}
