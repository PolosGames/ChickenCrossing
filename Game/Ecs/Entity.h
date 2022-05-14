#pragma once
#ifndef ENTITY_H_
#define ENTITY_H_

#include <cstdint>
#include <bitset>

#include "Globals.h"

using Entity   = std::uint64_t;
using CompMask = std::bitset<MAX_COMPONENTS>;

using EntityIndex = std::uint32_t;
using EntityVersion = std::uint32_t;

struct EntityData
{
    Entity id;
    CompMask mask;
};

constexpr inline Entity CreateEntity(EntityIndex index, EntityVersion version)
{
    // Shift the index up 32, and put the version in the bottom
    return ((Entity)index << 32) | ((Entity)version);
}
constexpr inline EntityIndex GetEntityIndex(Entity id)
{
    // Shift down 32 so we lose the version and get our index
    return id >> 32;
}
constexpr inline EntityVersion GetEntityVersion(Entity id)
{
    // Cast to a 32 bit int to get our version number (loosing the top 32 bits)
    return (EntityVersion)id;
}
constexpr inline bool IsEntityValid(Entity id)
{
    // Check if the index is our invalid index
    return (id >> 32) != EntityIndex(-1);
}

#define INVALID_ENTITY CreateEntity(static_cast<EntityId>(-1), 0)

#endif /* ENTITY_H_ */