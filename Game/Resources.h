#pragma once
#ifndef RESOURCES_H_
#define RESOURCES_H_

#include <Alias.h>

struct Resources
{
    Shader  texture_shader;
    
    // Type : 4 (White, Black, DBrown, LBrown)
    // ----> Anim : 4 (Idle, Walk, Sit, Run)
    // ---------> Frames : 4
    Texture chicken_anim[4][4][4];
    Texture tree[8];
    Texture road;

    ~Resources()
    {
        road.Delete();
        
        for (int i = 0; i < 4 * 4 * 4; i++)
        {
            chicken_anim[i / 16][(i / 4) % 4][i % 4].Delete();
        }

        for (auto const& t : tree)
        {
            t.Delete();
        }
    }
};

// don't ask, could not find any other way at the time
extern Resources* g_Resources;

#endif /* RESOURCES_H_ */