#pragma once
#ifndef COMPONENT_H_
#define COMPONENT_H_

static int s_CompCounter{ 0 };

template<typename T>
inline int GetComponentId()
{
    static int comp_id = s_CompCounter++;
    return comp_id;
}

#endif /* COMPONENT_H_ */