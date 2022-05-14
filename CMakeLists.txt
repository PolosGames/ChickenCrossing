cmake_minimum_required(VERSION 3.21)

project(ChickenCrossing)

add_subdirectory(Polos)

add_executable(ChickenCrossing)

set(ChickenCrossing_SOURCES
    "Game/EntryPoint.cpp"
    "Game/Renderer.cpp"
    "Game/Game.cpp"
    "Game/AnimationManager.cpp"
    "Game/Ecs/Scene.cpp"
    "Game/Ecs/ComponentMemory.cpp"
    "Game/Ecs/SceneViewIterator.cpp"
)

set(ChickenCrossing_HEADERS
    "Game/Alias.h"
    "Game/AnimationManager.h"
    "Game/EntryPoint.h"
    "Game/Game.h"
    "Game/Globals.h"
    "Game/GMath.h"
    "Game/Objects.h"
    "Game/Renderer.h"
    "Game/Resources.h"
    "Game/Ecs/base_scene_view.h"
    "Game/Ecs/Component.h"
    "Game/Ecs/ComponentMemory.h"
    "Game/Ecs/ComponentPool.h"
    "Game/Ecs/Entity.h"
    "Game/Ecs/Scene.h"
    "Game/Ecs/Scene.inl"
    "Game/Ecs/SceneView.h"
    "Game/Ecs/SceneViewIterator.h"
)

target_sources(ChickenCrossing 
    PRIVATE
        ${ChickenCrossing_SOURCES}
        ${ChickenCrossing_HEADERS}
)

target_link_libraries(ChickenCrossing PUBLIC Runtime)

target_compile_features(ChickenCrossing PRIVATE cxx_std_20)

target_include_directories(ChickenCrossing PRIVATE Game)

install(TARGETS ChickenCrossing DESTINATION bin/${CMAKE_BUILD_TYPE})
install(DIRECTORY resources DESTINATION bin/${CMAKE_BUILD_TYPE})