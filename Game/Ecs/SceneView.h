#pragma once
#ifndef SCENEVIEW_H_
#define SCENEVIEW_H_

#include "Scene.h"
#include "Entity.h"
#include "base_scene_view.h"
#include "SceneViewIterator.h"

template<typename... Components>
class SceneView : public base_scene_view
{
    using iterator       = SceneViewIterator;
    using const_iterator = iterator const;
public:
    SceneView(Scene& scene) 
    {
        m_Scene = &scene;
        if (sizeof...(Components) == 0)
        {
            m_IterateAll = true;
        }
        
        int comp_ids[] = { GetComponentId<Components>()... };

        for (int const& id : comp_ids)
        {
            m_Mask.set(id);
        }
    }

    iterator begin() const noexcept
    {
        return iterator{ reinterpret_cast<base_scene_view const*>(this), static_cast<EntityIndex>(0)};
    }

    iterator end() const noexcept
    {
        return iterator{ reinterpret_cast<base_scene_view const*>(this), static_cast<EntityIndex>(MAX_ENTITIES) };
    }
};

#endif /* SCENEVIEW_H_ */