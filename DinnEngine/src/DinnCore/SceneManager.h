#pragma once
#include "Scene.h"

namespace Dinn
{
    class SceneManager
    {
    public:
        SceneManager();
        ~SceneManager();
        
        template<class T, class ... Args>
        T& CreateScene(std::string sceneName, Args&&... args)
        {
            static_assert(std::is_base_of_v<Scene, T>, "T must derive from Scene");
            
            auto scene = std::make_unique<T>(sceneName, std::forward<Args>(args)...);
            T& ref = *scene;
            
            DN_CORE_INFO("Created Scene: {0}", sceneName);
            
            scenes.push_back(std::move(scene));
            return ref;
        }
        
        Scene* GetScene(std::string sceneName) const;
        Scene* GetScene(unsigned int id) const;
        Scene* GetCurrentScene();
        
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

