#pragma once
#ifndef RESOURCES_H_
#define RESOURCES_H_

#include <Alias.h>

struct Resources
{
    Shader* texture_shader;
    
    // Type : 4 (White, Black, DBrown, LBrown)
    // ----> Anim : 4 (Idle, Walk, Sit, Run)
    // ---------> Frames : 4
    TextureRef chicken_anim[4][4][4];
    TextureRef tree[8];
    TextureRef road;
};

// don't ask, could not find any other way at the time
extern Resources* g_Resources;

#endif /* RESOURCES_H_ */