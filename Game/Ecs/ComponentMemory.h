#pragma once
#ifndef COMPONENTMEMORY_H_
#define COMPONENTMEMORY_H_

#include <cstdlib>

#include <polos/debug/plassert.h>

#include "Globals.h"

class CompMem
{
public:
    CompMem(size_t size);
    ~CompMem();

    template<typename T>
    static void* Request()
    {
        size_t comp_size     = sizeof(T);
        size_t required_size = comp_size * MAX_ENTITIES;
        ASSERT(s_Instance->m_Offset + required_size <= s_Instance->m_AllocSize);

        void* ret_ptr = static_cast<char*>(s_Instance->m_Data) + s_Instance->m_Offset;
        s_Instance->m_Offset = required_size;
        return ret_ptr;
    }

    template<typename T>
    static void Clear(void* offset_ptr)
    {
        T* list = static_cast<T*>(offset_ptr);
        for (size_t i = 0; i < MAX_ENTITIES; i++)
        {
            list[i].~T();
        }
    }
private:
    void*  m_Data;
    size_t m_Offset;
    size_t m_AllocSize;

    friend class EntryPoint;
    static CompMem* s_Instance;
};

#endif /* COMPONENTMEMORY_H_ */