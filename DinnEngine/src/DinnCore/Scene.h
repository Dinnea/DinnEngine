#pragma once
#include "Core.h"
#include "dnpch.h"

#include "Components/Sprite.h"

namespace Dinn
{
    class GameObject;

   class DINN_API Scene
    {
    public:
        Scene();
        Scene(std::string SceneName);
        virtual ~Scene();
       
       Scene(const Scene&) = delete;
       Scene& operator=(const Scene&) = delete;
        
        void StartFrame();
        void Update(double deltaTime);
        void EndFrame();
       
        virtual void OnStartFrame() {} 
        virtual void OnUpdate(double deltaTime){}
        virtual void OnEndFrame(){}
       
        void RegisterSprite(Sprite* sprite);
        void UnregisterSprite(Sprite* spritesToRender);
       
        
        std::string name = "Scene";
        
        GameObject& CreateGameObject();
       
       /// <summary>
       /// Marks a game object for destroying at the end of the frame.
       /// </summary>
       void Destroy(const GameObject& gameObject);
        
    private:
       void RegisterPendingObjects();
       void DestroyPendingObjects();
       
        std::unordered_map<unsigned int, std::unique_ptr<GameObject>> gameObjects;
        std::unordered_map<unsigned int, std::unique_ptr<GameObject>> pendingGameObjects;
        std::vector<unsigned int> destroyQueue;
       
        std::vector<Sprite*> sprites;
        
        //unsigned int id = 0;
    };
}

