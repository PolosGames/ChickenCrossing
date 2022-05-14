#include <polos/polos_pch.h>

#include "ComponentMemory.h"

CompMem* CompMem::s_Instance;

CompMem::CompMem(size_t size)
    : m_Data{ std::malloc(size) },
      m_Offset{ 0 },
      m_AllocSize{ size }
{

}

CompMem::~CompMem()
{
    std::free(m_Data);
}