#include "dnpch.h"
#include "Scene.h"

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
        OnStartFrame();
    }

    void Scene::Update(double deltaTime)
    {       
        SpriteRenderer *renderer = SpriteRenderer::GetInstance();
        renderer->InitFrame();
        
        for (auto& [id, objPtr] : gameObjects)
        {
            objPtr->Update();

            auto* sprite = objPtr->GetComponent<Sprite>();
            Transform* transform = objPtr->GetTransform();

            if (sprite)
                renderer->Draw(*sprite, *transform);
        }
        OnUpdate(deltaTime);
    }

    void Scene::EndFrame()
    {
        ExeDestroyObjects();
        OnEndFrame();
    }

    GameObject& Scene::CreateGameObject()
    {
        unsigned int id = Application::GenerateGameObjectId();
        auto obj = std::make_unique<GameObject>(id);
        auto& ref = *obj;

        gameObjects.emplace(id, std::move(obj));

        DN_CORE_INFO("Created GameObject {0}", id);

        return ref;
    }

    void Scene::Destroy(GameObject& gameObject)
    {
        destroyQueue.push_back(gameObject.ID());
    }

    void Scene::ExeDestroyObjects()
    {
        for (auto id : destroyQueue)
        { 
            gameObjects.erase(id);
            DN_CORE_INFO("Destroyed GameObject {0}", id);
        }
		
        destroyQueue.clear();
    }
}


