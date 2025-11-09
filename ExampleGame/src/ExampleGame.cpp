#include "Dinn.h"

class Example : public Dinn::Application
{
public:
	Example()
	{
		SetTargetFrameRate(60); 

		Dinn::AssetManager& assetManager = GetAssetManager();

		auto willow = assetManager.LoadTexture("willow.png");

		Dinn::GameObject& objectA = CreateGameObject();
		Dinn::Transform* transformA = objectA.GetTransform();

		transformA->scale = glm::vec2(250, 250);
		transformA->position = glm::vec2(500, 500);
		objectA.AddComponent<Dinn::Sprite>(willow);

		Dinn::GameObject& objectB = CreateGameObject();
		Dinn::Transform* transformB = objectB.GetTransform();

		transformB->scale = glm::vec2(100, 100);
		transformB->position = glm::vec2(600, 700);
		objectB.AddComponent<Dinn::Sprite>();
	}

	~Example()
	{

	}
};

Dinn::Application* Dinn::CreateApplication()
{
	return new Example();
}
