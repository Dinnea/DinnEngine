#pragma once
#include "DinnCore/Input.h"
#include "DinnCore/Components/Component.h"

class TestClass : public Dinn::Component
{
public:
    explicit TestClass(Dinn::GameObject& owner)
        : Component(owner)
    {
    }

protected:
    void Update() override
    {
        if (Dinn::Input::GetKeyDown(Dinn::Input::Keyboard::W))
        {
            owner->GetTransform()->position += glm::vec2(0, 1);
        }
		
        if (Dinn::Input::GetKeyDown(Dinn::Input::Keyboard::S))
        {
            owner->GetTransform()->position += glm::vec2(0, -1);
        }
		
        if (Dinn::Input::GetKeyDown(Dinn::Input::Keyboard::A))
        {
            owner->GetTransform()->position += glm::vec2(-1, 0);
        }
		
        if (Dinn::Input::GetKeyDown(Dinn::Input::Keyboard::D))
        {
            owner->GetTransform()->position += glm::vec2(1, 0);
        }
    }
};
