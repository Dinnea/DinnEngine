#pragma once
#include "DinnCore/Rendering/Texture.h"

namespace Dinn
{
	class DINN_API AssetManager
	{
	public:
		AssetManager();
		~AssetManager();

		std::shared_ptr<Texture> GetDefaultTexture() { return defaultTexture; }
		std::shared_ptr<Shader> GetDefaultShader() { return defaultShader; }

		/// <summary>
		/// Loads a texture from the games's asset directory.
		/// .png and .jpg supported ONLY
		/// 
		/// Path is **relative to** "Resources/Textures/"
		/// Examples:
		/// LoadTexture("Player.png")			→ "Resources/Textures/Player.png"
		/// LoadTexture("Enemies/Goblin.png")   → "Resources/Textures/Enemies/Goblin.png"
		///
		/// Do NOT include the base folder, absolute paths, or leading slashes.
		/// Correct:    LoadTexture("UI/Button.png")
		/// Incorrect:  LoadTexture("Resources/Textures/UI/Button.png")
		/// Incorrect:  LoadTexture("/UI/Button.png")
		/// </summary>
		/// <param name="path"></param>
		/// <returns></returns>
		std::shared_ptr<Texture> LoadTexture(const std::string& path);

		/// Loads a shader program from the engine's shader directory.
		///
		/// Both paths are **relative to** "Resources/Shaders/"
		///
		/// Examples:
		///   LoadShader("Sprite.vert", "Sprite.frag")
		///        → "Resources/Shaders/Sprite.vert"
		///        → "Resources/Shaders/Sprite.frag"
		///
		///   LoadShader("UI/Text.vert", "UI/Text.frag")
		///        → "Resources/Shaders/UI/Text.vert"
		///        → "Resources/Shaders/UI/Text.frag"
		///
		/// Do NOT include the base folder, absolute paths, or leading slashes.
		/// Correct:    LoadShader("Lighting/Phong.vert", "Lighting/Phong.frag")
		/// Incorrect:  LoadShader("Resources/Shaders/Lighting/Phong.vert", ...)
		/// Incorrect:  LoadShader("/Lighting/Phong.vert", ...)
		std::shared_ptr<Shader> LoadShader(const std::string& vertexPath, const std::string& fragmentPath);

	private:
		std::unordered_map<std::string, std::shared_ptr<Texture>> textureCache;
		std::unordered_map<std::string, std::shared_ptr<Shader>> shaderCache;

		std::shared_ptr<Texture> defaultTexture;
		std::shared_ptr<Shader> defaultShader;
	};
}
