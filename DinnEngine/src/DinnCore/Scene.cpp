#include "dnpch.h"
#include "Scene.h"

#include <deque>
#include <ranges>

#include "DinnCore/Application.h"
#include "DinnCore/GameObject.h"

namespace Dinn
{
    Scene::Scene()
    {
    }

    Scene::Scene(std::string SceneName) : name(SceneName)
    {
    }

    Scene::~Scene()
    {
    }

    void Scene::StartFrame()
    {
        RegisterPendingObjects();
        
        OnStartFrame();
    }

    void Scene::Update(double deltaTime)
    {       
        SpriteRenderer *renderer = SpriteRenderer::GetInstance();
        renderer->InitFrame();
        
        for (const auto& objPtr : gameObjects | std::views::values)
        {
            objPtr->Update();
        }
        OnUpdate(deltaTime);

        for (auto sprite : sprites)
            renderer->Draw(*sprite);
        
    }

    void Scene::EndFrame()
    {
        DestroyPendingObjects();
        OnEndFrame();
    }

    void Scene::RegisterSprite(Sprite* sprite)
    {
        if (sprite) sprites.push_back(sprite);
    }

    void Scene::UnregisterSprite(Sprite* spritesToRender)
    {
        if(spritesToRender) std::erase(sprites, spritesToRender);
    }

    GameObject& Scene::CreateGameObject()
    {
        unsigned int id = Application::GenerateGameObjectId();
        auto obj = std::make_unique<GameObject>(id, *this);
        auto& ref = *obj;

        pendingGameObjects.emplace(id, std::move(obj));

        DN_CORE_INFO("Created GameObject {0}", id);

        return ref;
    }

    void Scene::Destroy(const GameObject& gameObject)
    {
        destroyQueue.push_back(gameObject.ID());
    }

    void Scene::RegisterPendingObjects()
    {
        for (const auto val : pendingGameObjects | std::views::values)
        {
            val->SetActive(true);
            if (auto* sprite = val->GetComponent<Sprite>())
                sprites.push_back(sprite);
        }
        
        gameObjects.merge(pendingGameObjects);
    }

    void Scene::DestroyPendingObjects()
    {
        for (auto id : destroyQueue)
        { 
            gameObjects.erase(id);
            DN_CORE_INFO("Destroyed GameObject {0}", id);
        }
		
        destroyQueue.clear();
    }
}


