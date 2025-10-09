#pragma once
#include "RendererComponents.h"
#include "glm.hpp"

namespace Dinn
{
	class Renderer2D
	{
    public:
        Renderer2D();
        ~Renderer2D();

        void Initialize();
        void Draw();
        void Shutdown();
        void SetProjection(float width, float height);

    private:
        VAO vao;
        std::unique_ptr<VBO> vbo;
        std::unique_ptr <EBO> ebo;
        std::shared_ptr<Shader> shader;
	};
}
