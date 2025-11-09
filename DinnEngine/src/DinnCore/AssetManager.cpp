#include "dnpch.h"
#include "AssetManager.h"

namespace Dinn
{
    AssetManager::AssetManager()
    {
        defaultTexture = LoadTexture("default.jpg");
        defaultShader = LoadShader("default.vert", "default.frag");
    }

    AssetManager::~AssetManager()
    {
    }

    std::shared_ptr<Texture> AssetManager::LoadTexture(const std::string& path)
    {
        DN_CORE_INFO("Loading texture: {0}", path);

        //check if valid
        const bool isPng = path.ends_with(".png");
        const bool isJpg = path.ends_with(".jpg") || path.ends_with(".jpeg");

        if (!(isPng || isJpg))
        {
            DN_CORE_ERROR("Bad path for texture import. Only .png and .jpg are supported. Returning nullptr.");
            return nullptr;
        }

        //If texture loaded, return it
        if (auto iterator = textureCache.find(path); iterator != textureCache.end())
            return iterator->second;

        //else load new texture
        std::shared_ptr<Texture> tex;

        std::string fullPath = "Resources/Textures/" + path;

        // PNG needs GL_RGBA
        if (isPng)
           tex = std::make_shared<Texture>(fullPath.c_str(), GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);

        // JPG needs GL_RGB
        if(isJpg)
           tex = std::make_shared<Texture>(fullPath.c_str(), GL_TEXTURE_2D, GL_TEXTURE0, GL_RGB, GL_UNSIGNED_BYTE);

        textureCache[path] = tex;

        return tex;
    }

    std::shared_ptr<Shader> AssetManager::LoadShader(const std::string& vertexPath, const std::string& fragmentPath)
    {
        DN_CORE_INFO("Loading shader: {0} | {1}", vertexPath, fragmentPath);

        const bool isPathValid = (vertexPath.ends_with(".vert") && (fragmentPath.ends_with(fragmentPath)));

        if (!isPathValid)
        {
            DN_CORE_ERROR("Bad path for shader import. vertexPath needs to end in .vert, fragmentPath in .frag, returning nullptr");
            return nullptr;
        }

        std::string key = vertexPath + "&" + fragmentPath;

        //If shader loaded, return it
        if (auto iterator = shaderCache.find(key); iterator != shaderCache.end())
            return iterator->second;

        std::string fullPathVertex = "Resources/Shaders/" + vertexPath;
        std::string fullPathFragment = "Resources/Shaders/" + fragmentPath;

        //Else load new shader
        auto shader = std::make_shared<Shader>(fullPathVertex.c_str(), fullPathFragment.c_str());

        shaderCache[key] = shader;

        return shader;
    }

}
