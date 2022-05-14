#pragma once
#ifndef CHICKEN_H_
#define CHICKEN_H_

#include "../Components.h"

enum ChickenType
{
    White,
    Black,
    DBrown,
    LBrown,

    kMaxChickenType,
};

enum ChickenAnim
{
    Idle,
    Walk,
    Sit,
    Run,

    kMaxChickenAnim
};

struct Chicken
{
    ChickenType type;
    ChickenAnim anim;

    TransformComponent* comp_transform;
    AnimationComponent* comp_animation;
};

#endif /* CHICKEN_H_ */