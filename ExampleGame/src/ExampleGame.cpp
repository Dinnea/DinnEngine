#include "Dinn.h"

class Example : public Dinn::Application
{
public:
	Example()
	{
		SetTargetFrameRate(60);
	}

	~Example()
	{

	}
};

Dinn::Application* Dinn::CreateApplication()
{
	return new Example();
}
