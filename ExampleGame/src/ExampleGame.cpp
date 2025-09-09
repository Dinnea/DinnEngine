#include "Dinn.h"

class Example : public Dinn::Application
{
public:
	Example()
	{

	}

	~Example()
	{

	}
};

Dinn::Application* Dinn::CreateApplication()
{
	return new Example();
}


