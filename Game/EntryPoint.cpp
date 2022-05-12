#include <polos/polos_pch.h>

#include <glad/glad.h>
#include <imgui.h>

#include <polos.h>
#include <polos/core/update_queue.h>
#include <polos/context/vertex.h>
#include <polos/context/shader_lib.h>
#include <polos/utils/stringid.h>
#include <polos/core/camera.h>
#include <polos/utils/macro_util.h>

#include "Renderer.h"
#include "Resources.h"
#include "Game.h"
#include "Objects.h"

#include "EntryPoint.h"

Resources* g_Resources = new Resources{};

EntryPoint::EntryPoint(pl::window_props&& props)
    : pl::Application(std::forward<pl::window_props>(props))
{
    UPDATE_Q_MEM_ADD_LAST(EntryPoint, Update);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Load all shaders
    pl::ShaderLib::Load("resources/shaders/texture.vert", "resources/shaders/texture.frag");

    // Initialize global resources
    g_Resources->texture_shader = &pl::ShaderLib::Get("texture"_sid);
    g_Resources->tree[0]        = pl::Texture::Load("resources/textures/tree/tree_1.png");
    g_Resources->tree[1]        = pl::Texture::Load("resources/textures/tree/tree_2.png");
    g_Resources->tree[2]        = pl::Texture::Load("resources/textures/tree/tree_3.png");
    g_Resources->tree[3]        = pl::Texture::Load("resources/textures/tree/tree_4.png");
    g_Resources->tree[4]        = pl::Texture::Load("resources/textures/tree/tree_5.png");
    g_Resources->tree[5]        = pl::Texture::Load("resources/textures/tree/tree_6.png");
    g_Resources->tree[6]        = pl::Texture::Load("resources/textures/tree/tree_7.png");
    g_Resources->tree[7]        = pl::Texture::Load("resources/textures/tree/tree_8.png");

    Array<std::string, ChickenType::kMaxChickenType> const chicken_types {
        "white", "black", "dbrown", "lbrown"
    };
    Array<std::string, ChickenAnim::kMaxChickenAnim> const chicken_anim {
        "idle", "walk", "sit", "run"
    };
    for (auto i = 0; i < ChickenType::kMaxChickenType; i++)
    {
        for (auto j = 0; j < ChickenAnim::kMaxChickenAnim; j++)
        {
            for (auto k = 0; k < 4; k++)
            {
                std::string path = "resources/textures/chickens/" + chicken_types[i] + "/chicken_"
                                    + chicken_anim[j] + "_" + std::to_string(k + 1) + ".png";
                g_Resources->chicken_anim[i][j][k] = pl::Texture::Load(path);
            }
        }
    }

    InitializeRenderer();
}

void EntryPoint::Update(float delta_time)
{
}

EntryPoint::~EntryPoint()
{
    delete g_Resources;
}

polos::Application* polos::CreateApplication(void* ptr)
{
    window_props props {};
    props.title        = "Chicken Crossing";
    props.width        = 1920; // width
    props.height       = 1080; // height
    props.refresh_rate = 60;   // refresh rate
    props.vsync        = true; // vsync
    props.fullscreen   = false; // fullscreen

    Application* app = ptr == nullptr ? new EntryPoint{ std::move(props) } : new (ptr) EntryPoint{std::move(props)};

    return app;
}