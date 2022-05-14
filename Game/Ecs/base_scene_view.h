#pragma once
#ifndef BASESCENEVIEW_H_
#define BASESCENEVIEW_H_

#include "Scene.h"

struct base_scene_view
{
    Scene*   m_Scene{};
    CompMask m_Mask;
    bool     m_IterateAll;
};


#endif /* BASESCENEVIEW_H_ */