#include <polos/context/shader.h>

struct Resources
{
    polos::Shader texture_shader;

    static Resources* Instance;
};