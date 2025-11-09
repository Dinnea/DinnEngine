#pragma once
#include "DinnCore/Rendering/Components/Shader.h"
#include "Component.h"
#include "Rendering/Texture.h"

namespace Dinn
{
	struct DINN_API Sprite : Component
	{
		friend class GameObject;

	public:
		void SetTexture(std::shared_ptr<Texture> texture) { this->texture = std::move(texture); }
		void SetShader(std::shared_ptr<Shader> shader) { this->shader = std::move(shader); }

		void ClearTexture() { texture.reset(); }
		void ClearShader() { shader.reset(); }

		std::shared_ptr<Texture> GetTexture() const { return texture.lock(); }
		std::shared_ptr<Shader> GetShader() const { return shader.lock();}

		bool HasTextureOverride() { return !texture.expired(); }
		bool HasShaderOverrride() {	return !shader.expired(); }

		explicit Sprite(GameObject& owner) 
			: Component(owner) {}
		explicit Sprite(GameObject& owner, std::shared_ptr<Texture> texture) 
			: Component(owner), texture(texture) {}
		explicit Sprite(GameObject& owner, std::shared_ptr<Shader> shader) 
			: Component(owner), shader(shader) {}
		explicit Sprite(GameObject& owner, std::shared_ptr<Texture> texture, std::shared_ptr<Shader> shader)
			: Component(owner), texture(texture), shader(shader) {}

	protected:
		std::weak_ptr<Shader> shader;
		std::weak_ptr<Texture> texture;
	};
}

