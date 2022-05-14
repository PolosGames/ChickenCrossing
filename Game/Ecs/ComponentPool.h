#pragma once
#ifndef ICOMPONENTPOOL_H_
#define ICOMPONENTPOOL_H_

#include <cstdint>

#include "ComponentMemory.h"

struct IComponentPool
{
    void* m_Data{};
    size_t m_ElemSize{};
    
    void* Get(size_t index)
    {
        return static_cast<std::byte*>(m_Data) + (index * m_ElemSize);
    }
};

template<typename T>
class ComponentPool : public IComponentPool
{
public:
    ComponentPool() : IComponentPool{CompMem::Request<T>(), sizeof(T)} {}
    ~ComponentPool() { CompMem::Clear<T>(m_Data); }
    
    ComponentPool(ComponentPool&& other)
    {
        m_ElemSize = std::exchange(other.m_ElemSize, 0);
        m_Data     = std::exchange(other.m_Data, nullptr);
    }

    ComponentPool& operator==(ComponentPool&& other)
    {
        if (this == &other) return *this;
        m_ElemSize = std::exchange(other.m_ElemSize, 0);
        m_Data     = std::exchange(other.m_Data, nullptr);
    }
};

#endif /* ICOMPONENTPOOL_H_ */