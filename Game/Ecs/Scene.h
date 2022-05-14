#pragma once
#ifndef SCENE_H_
#define SCENE_H_

#include "Globals.h"
#include "ComponentPool.h"
#include "Entity.h"
#include "Component.h"

class Scene
{
public:
    Scene();

    Entity NewEntity();
    void   DestroyEntity(Entity entt);

    template<typename T, typename... Args>
    T* Assign(Entity entt, Args&&... args);

    template<typename T>
    T* Assign(Entity entt, T&& other);

    template<typename T>
    T* Get(Entity entt);

    template<typename T>
    void Remove(Entity entt);
private:
    friend class SceneViewIterator;
    uint32_t                 m_EntitySize{};
    std::vector<EntityIndex> m_FreeEntities;

    std::array<EntityData, MAX_ENTITIES>       m_Entities;
    std::array<IComponentPool, MAX_COMPONENTS> m_CompPools;
};

#include "Scene.inl"

#endif /* SCENE_H_ */