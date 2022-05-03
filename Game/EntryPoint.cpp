#include <polos.h>
#include <polos/core/update_queue.h>

#include "EntryPoint.h"

EntryPoint::EntryPoint()
{
    using polos::UpdateQueue;
    using Ftype = UpdateQueue::FuncType;
    UpdateQueue::PutLast(Ftype::From<EntryPoint, &EntryPoint::Update>(this));
}

void EntryPoint::Update(float delta_time)
{

}

polos::Application* polos::CreateApplication(void* ptr)
{
    return ptr == nullptr ? new EntryPoint() : new (ptr) EntryPoint();
}