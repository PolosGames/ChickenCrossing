#pragma once
#ifndef SCENEVIEWITERATOR_H_
#define SCENEVIEWITERATOR_H_

#include "base_scene_view.h"
#include "Entity.h"

class SceneViewIterator
{
public:
    SceneViewIterator(base_scene_view const* view, EntityIndex index);

    Entity& operator*() const;

    bool operator==(const SceneViewIterator& other) const;
    bool operator!=(const SceneViewIterator& other) const;

    SceneViewIterator& operator++();
    SceneViewIterator  operator++(int);
private:
    bool CheckValid();
private:
    EntityIndex m_Index{};
    base_scene_view const* m_View;
};

#endif /* SCENEVIEWITERATOR_H_ */