#include "TestScene.h"

#include <vec2.hpp>

#include "TestClass.h"
#include "DinnCore/AssetManager.h"
#include "DinnCore/GameObject.h"
#include "DinnCore/Transform.h"
#include "DinnCore/Components/Sprite.h"

TestScene::TestScene(std::string sceneName)
{    
    Dinn::AssetManager* assetManager = &Dinn::AssetManager::GetInstance();
    
    auto willow = assetManager->LoadTexture("willow.png");
    
    Dinn::GameObject& objectA = CreateGameObject();
    Dinn::Transform* transformA = objectA.GetTransform();
    
    transformA->scale = glm::vec2(250, 250);
    transformA->position = glm::vec2(500, 500);
    objectA.AddComponent<Dinn::Sprite>(willow);
    objectA.AddComponent<TestClass>();
    
    Dinn::GameObject& objectB = CreateGameObject();
    Dinn::Transform* transformB = objectB.GetTransform();
    
    transformB->scale = glm::vec2(100, 100);
    transformB->position = glm::vec2(600, 700);
    objectB.AddComponent<Dinn::Sprite>();
}

TestScene::~TestScene()
= default;
