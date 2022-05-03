#pragma once
#ifndef ENTRYPOINT_H_
#define ENTRYPOINT_H_

#include <polos/core/application.h>

class EntryPoint : public polos::Application
{
public:
    EntryPoint();

    void Update(float delta_time);
};

#endif /* ENTRYPOINT_H_ */