template<typename T, typename... Args>
inline T* Scene::Assign(Entity entt, Args&&... args)
{
    int         comp_id    = GetComponentId<T>();
    EntityIndex entt_index = GetEntityIndex(entt);

    if (m_Entities[entt_index].id != entt)
    {
        return nullptr;
    }

    if (m_CompPools[comp_id].m_Data == nullptr)
    {
        m_CompPools[comp_id] = std::move(ComponentPool<T>());
    }

    T* comp_ptr = new (m_CompPools[comp_id].Get(entt_index)) T(std::forward<Args>(args)...);

    m_Entities[entt_index].mask.set(comp_id);

    return comp_ptr;
}

template<typename T>
inline T* Scene::Assign(Entity entt, T&& other)
{
    int         comp_id    = GetComponentId<T>();
    EntityIndex entt_index = GetEntityIndex(entt);

    if (m_Entities[entt_index].id != entt)
    {
        return nullptr;
    }

    if (m_CompPools[comp_id].m_Data == nullptr)
    {
        m_CompPools[comp_id] = std::move(ComponentPool<T>());
    }

    T* comp_ptr = new (m_CompPools[comp_id].Get(entt_index)) T(std::forward<T>(other));

    m_Entities[entt_index].mask.set(comp_id);

    return comp_ptr;
}

template<typename T>
inline T* Scene::Get(Entity entt)
{
    int         comp_id    = GetComponentId<T>();
    EntityIndex entt_index = GetEntityIndex(entt);

    if (m_Entities[entt_index].id != entt)
    {
        return nullptr;
    }

    if (!m_Entities[entt_index].mask.test(comp_id))
        return nullptr;

    T* pComponent = static_cast<T*>(m_CompPools[comp_id].Get(entt_index));
    return pComponent;
}

template<typename T>
inline void Scene::Remove(Entity entt)
{
    int         comp_id = GetComponentId<T>();
    EntityIndex entt_index = GetEntityIndex(entt);

    if (m_Entities[entt_index].id != entt)
    {
        return;
    }

    m_Entities[entt_index].mask.reset();
}