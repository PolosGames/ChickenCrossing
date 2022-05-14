#include <polos/polos_pch.h>

#include "Scene.h"

Scene::Scene()
{
}

Entity Scene::NewEntity()
{
    if (!m_FreeEntities.empty())
    {
        EntityIndex entt_index = m_FreeEntities.back();
        EntityData& entt_data = m_Entities[entt_index];
        Entity new_entt_id = CreateEntity(entt_index, GetEntityVersion(entt_data.id));

        entt_data.id = new_entt_id;

        m_FreeEntities.pop_back();
        return new_entt_id;
    }

    EntityIndex entt_index = static_cast<EntityIndex>(m_EntitySize++);

    EntityData data;
    data.id   = CreateEntity(entt_index, static_cast<EntityVersion>(0));
    data.mask = CompMask{};

    m_Entities[entt_index] = std::move(data);
    return entt_index;
}

void Scene::DestroyEntity(Entity entt)
{
    EntityIndex entt_index = GetEntityIndex(entt);
    Entity      newID      = CreateEntity(static_cast<EntityIndex>(-1), GetEntityVersion(entt) + 1);

    // Invalidate the entity
    m_Entities[entt_index].id = newID;
    m_Entities[entt_index].mask.reset();

    m_FreeEntities.push_back(entt_index);
}
