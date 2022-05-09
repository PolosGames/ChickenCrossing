#include <polos/polos_pch.h>

#include <imgui.h>
#include <polos/core/update_queue.h>

#include "Renderer.h"
#include "Resources.h"

#include "Game.h"

Game::Game()
{
    UPDATE_Q_MEM_ADD_LAST(Game, Update);
}

void Game::Update(float delta_time)
{
    RenderTexture(g_Resources->chicken_anim[0][0][0], {200, 200, 0}, {256, 256}, 0.0f);
}
