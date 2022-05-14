#pragma once
#ifndef ANIMATIONMANAGER_H_
#define ANIMATIONMANAGER_H_

class AnimationManager
{
public:
    static void Update(float delta_time);
private:
    friend class EntryPoint;
    static AnimationManager* s_Instance;
};

#endif /* ANIMATIONMANAGER_H_ */