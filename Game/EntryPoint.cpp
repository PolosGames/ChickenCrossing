#include <polos/polos_pch.h>

#include <glad/glad.h>
#include <imgui.h>

#include <polos.h>
#include <polos/core/update_queue.h>
#include <polos/context/vertex.h>
#include <polos/context/shader_lib.h>
#include <polos/utils/stringid.h>
#include <polos/core/camera.h>

#include "Renderer.h"
#include "Resources.h"

#include "EntryPoint.h"

Resources* Resources::Instance;

EntryPoint::EntryPoint(pl::window_props&& props)
    : pl::Application(std::forward<pl::window_props>(props))
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    using Ftype = pl::UpdateQueue::FuncType;
    pl::UpdateQueue::PutLast(Ftype::From<EntryPoint, &EntryPoint::Update>(this));
    pl::ShaderLib::Load("resources/shaders/texture.vert", "resources/shaders/texture.frag");

    // Initialize global resources
    Resources::Instance = new Resources{};
    Resources::Instance->texture_shader = pl::ShaderLib::Get("texture"_sid);

    texture  = pl::Texture::Load("resources/textures/tree/tree_1.png");
    position = { 0.0f, 0.0f, 0.0f };
    size     = { 128.0f, 256.0f };
    rotation = 0.0f;

    InitializeRenderer();
}

void EntryPoint::Update(float delta_time)
{
    ImGui::Begin("Texture Position");
    ImGui::SliderFloat3("Pos", glm::value_ptr(position), -640, 640);
    ImGui::SliderFloat2("Size", glm::value_ptr(size), -640, 640);
    ImGui::SliderFloat("Rotation", &rotation, -3000, 3000);
    ImGui::End();
    RenderTexture(texture, position, size, rotation);
}

EntryPoint::~EntryPoint()
{
    delete Resources::Instance;
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