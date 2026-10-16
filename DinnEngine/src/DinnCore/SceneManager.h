#pragma once
#include "Scene.h"
#include "Core.h"

namespace Dinn
{
    class DINN_API SceneManager
    {
    public:
        SceneManager() = default;
        ~SceneManager() = default;
        SceneManager(const SceneManager&) = delete;
        SceneManager& operator=(const SceneManager&) = delete;
        
        template<class T, class ... Args>
        T& CreateScene(std::string sceneName, Args&&... args)
        {
            static_assert(std::is_base_of_v<Scene, T>, "T must derive from Scene");
            
            auto scene = std::make_unique<T>(sceneName, std::forward<Args>(args)...);
            T& ref = *scene;
            
            DN_CORE_INFO("Created Scene: {0}", sceneName);
            
            if (currentScene == nullptr)
                currentScene = scene.get();
            
            scenes.push_back(std::move(scene));
            
            return ref;
        }
        
        Scene* GetScene(std::string sceneName) const;
        Scene* GetScene(unsigned int id) const;
        Scene* GetCurrentScene() const;
        
        void SetCurrentScene(Scene& scene);
        void SetCurrentScene(std::string sceneName);
        void SetCurrentScene(unsigned int id);
        void ReloadScene();
                
        unsigned int GetSceneCount() const {return scenes.size();}
        
    private:
        std::vector<std::unique_ptr<Scene>> scenes;
        Scene* currentScene = nullptr
        ;
    }; 
}

