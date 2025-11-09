#include "dnpch.h"
#include "AssetManager.h"

namespace Dinn
{
    AssetManager::AssetManager()
    {
        defaultTexture = LoadTexture("willow.png");
        defaultShader = LoadShader("default.vert", "default.frag");
    }

    AssetManager::~AssetManager()
    {

    }
    std::shared_ptr<Texture> AssetManager::LoadTexture(const std::string& path)
    {
        //check if valid
        const bool isPng = path.ends_with(".png");
        const bool isJpg = path.ends_with(".jpg") || path.ends_with(".jpeg");

        if (!(isPng && isJpg))
        {
            DN_CORE_ERROR("Bad format. Only .png and .jpg are supported. Returning nullptr.");
            return nullptr;
        }

        //If texture loaded, return it
        if (auto iterator = textureCache.find(path); iterator != textureCache.end())
            return iterator->second;

        //else load new texture
        std::shared_ptr<Texture> tex;

        // PNG needs GL_RGBA
        if (isPng)
           tex = std::make_shared<Texture>(("Resources/Textures/" + path,
            GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE));

        // JPG needs GL_RGB
        if(isJpg)
            tex = std::make_shared<Texture>(("Resources/Textures/" + path,
                GL_TEXTURE_2D, GL_TEXTURE0, GL_RGB, GL_UNSIGNED_BYTE));

        textureCache[path] = tex;

        return tex;
    }

    std::shared_ptr<Shader> AssetManager::LoadShader(const std::string& vertexPath, const std::string& fragmentPath)
    {
        const bool isPathValid = (vertexPath.ends_with(".vert") && (fragmentPath.ends_with(fragmentPath)));

        if (!isPathValid)
        {
            DN_CORE_ERROR("Bad format. vertexPath needs to end in .vert, fragmentPath in .frag, returning nullptr");
            return nullptr;
        }

        std::string key = vertexPath + "&" + fragmentPath;

        //If shader loaded, return it
        if (auto iterator = shaderCache.find(key); iterator != shaderCache.end())
            return iterator->second;

        //Else load new shader
        auto shader = std::make_shared<Shader>("Resources/Shaders/" + vertexPath, "Resources/Shaders/" + fragmentPath);

        shaderCache[key] = shader;

        return shader;
    }

}
