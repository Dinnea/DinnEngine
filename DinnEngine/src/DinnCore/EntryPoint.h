#pragma once
#ifdef DN_PLATFORM_WINDOWS

extern Dinn::Application* Dinn::CreateApplication();

int main(int argc, char** argv)
{
	printf("Dinn Engine launched. \n");
	auto app = Dinn::CreateApplication();
	app->Run();
	delete app;
}
#endif // DN_PLATFORM_WINDOWS
