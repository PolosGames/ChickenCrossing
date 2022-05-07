#include <polos/context/texture.h>
#include <polos/context/vao.h>

namespace constants
{
    extern const glm::mat4 k_Projection;
}

void InitializeRenderer();
void RenderTexture(pl::Texture const& texture, glm::vec3 const& position, 
                    glm::vec2 const& dimensions, float rotation);