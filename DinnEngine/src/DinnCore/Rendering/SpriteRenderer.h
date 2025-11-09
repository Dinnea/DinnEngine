#pragma once
#include "DinnCore/Sprite.h"
#include "DinnCore/Transform.h"
#include "RendererComponents.h"

namespace Dinn
{
	class SpriteRenderer
	{
    public:
        SpriteRenderer();
        ~SpriteRenderer();

        void Initialize();
        void Shutdown();

        void InitFrame();
        void Draw(const Sprite& sprite, const Transform& transform);
        void EndFrame();

        /// <summary>
        /// Renderer handles projection atm => no camera
        /// </summary>
        /// <param name="width"> => window width</param>
        /// <param name="height"> => window height</param>
        void SetProjection(float width, float height);

    private:

        glm::mat4 projection;
        glm::mat4 model;

        //quad
        VAO vao;
        std::unique_ptr<VBO> vbo;
        std::unique_ptr <EBO> ebo;
        std::shared_ptr<Shader> defaultShader;
        std::shared_ptr<Texture> defaultTexture;
	};
}
