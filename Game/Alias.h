#include <polos/context/shader.h>
#include <polos/context/texture.h>

using Shader    = pl::Shader;
using ShaderRef = std::shared_ptr<Shader>;

using Texture    = pl::Texture;
using TextureRef = std::shared_ptr<Texture>;

template<typename T, std::size_t Size>
using Array = std::array<T, Size>;