#pragma once
#ifdef DN_PLATFORM_WINDOWS

extern Dinn::Application* Dinn::CreateApplication();

int main(int argc, char** argv)
{
	printf("Dinn Engine launched. \n");

	Dinn::Log::Init();
	DN_CORE_INFO("Initialized log!");
	DN_INFO("Initialized log!");

	auto app = Dinn::CreateApplication();
	app->Run();
	delete app;
}
#endif // DN_PLATFORM_WINDOWS
