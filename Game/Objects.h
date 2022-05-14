#pragma once
#ifndef OBJECTS_H_
#define OBJECTS_H_

#include <polos/utils/alias.h>

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

#endif /* OBJECTS_H_ */