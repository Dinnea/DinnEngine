#include "dnpch.h"
#include "SceneManager.h"

namespace Dinn
{    
    Scene* SceneManager::GetScene(std::string sceneName) const
    {
        for (auto& scene : scenes)
            if (scene->name == sceneName)
                return scene.get();
        
        DN_CORE_WARN("SceneManager::GetScene: Scene \"{0}\" does not exist.", sceneName);
        return nullptr;
    }

    Scene* SceneManager::GetScene(unsigned int id) const
    {
        if (id >= scenes.size())
        {
            DN_CORE_WARN("SceneManager::GetScene: Scene \"{0}\" does not exist.", id);
            return nullptr;
        }
        
        return scenes[id].get();
    }

    Scene* SceneManager::GetCurrentScene() const
    {
        return currentScene;
    }

    void SceneManager::SetCurrentScene(Scene& scene)
    {
        auto* oldScene = currentScene;
        
        
        
        currentScene = &scene;
    }

    void SceneManager::SetCurrentScene(std::string sceneName)
    {
        if (auto* targetScene = GetScene(sceneName))
        {
            SetCurrentScene(*targetScene);
            DN_CORE_INFO("SceneManager::Set Current Scene: Scene \"{0}\".", sceneName);
        }
        else
        {
            DN_CORE_WARN("SceneManager::SetCurrentScene: Scene \"{0}\" does not exist.", sceneName);
        }
    }

    void SceneManager::SetCurrentScene(unsigned int id)
    {
        if (auto* targetScene = GetScene(id))
        {
            SetCurrentScene(*targetScene);
            DN_CORE_INFO("SceneManager::Set Current Scene: Scene \"{0}\".", id);
        }
        
        else
        {
            DN_CORE_WARN("SceneManager::SetCurrentScene: Scene \"{0}\" does not exist.", id);
        }
    }

    void SceneManager::ReloadScene()
    {
        
    }
}
