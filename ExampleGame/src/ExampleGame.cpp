#include "Dinn.h"
#include "TestClass.h"
#include "TestScene.h"
#include "DinnCore/Components/Sprite.h"
#include "DinnCore/GameObject.h"

class Example : public Dinn::Application
{
public:
	Example()
	{
		SetTargetFrameRate(60);
		TestScene* test = &sceneManager->CreateScene<TestScene>("test scene");
	}

	~Example() override
	{

	}
};

Dinn::Application* Dinn::CreateApplication()
{
	return new Example();
}


