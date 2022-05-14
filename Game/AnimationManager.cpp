#include <polos/polos_pch.h>

#include "Ecs/SceneView.h"
#include "Ecs/Entity.h"
#include "Components.h"
#include "Game.h"

#include "AnimationManager.h"

AnimationManager* AnimationManager::s_Instance;

void AnimationManager::Update(float delta_time)
{
    Scene& scene = Game::GetCurentScene();
    for (Entity& id : SceneView<AnimationComponent>{scene})
    {
        auto* anim = scene.Get<AnimationComponent>(id);
        (void)anim;
        if (anim->is_stopped) continue;

        if (anim->frame_ctr == anim->fps)
        {
            anim->frame_ctr = 0;
            anim->cur_frame++;
            if (anim->cur_frame == anim->max_frame)
            {
                if (!anim->loop)
                {
                    anim->is_stopped = true;
                    anim->cur_frame--;
                    continue;
                }
                anim->cur_frame = 0;
            }
        }
        anim->frame_ctr++;
    }
}
