#pragma once
#include "Core.h"
#include "Events/WindowEvent.h"
#include "Time.h"
#include "Window.h"
#include "Rendering/SpriteRenderer.h"
#include <chrono>
#include <thread>
#include "GameObject.h"

namespace Dinn
{
	class DINN_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		void SetTargetFrameRate(unsigned int frameRate);

		void OnEvent(Event& event);

		/// <summary>
		/// Marks a game object for destroying at the end of the frame.
		/// </summary>
		void Destroy(GameObject& gameObject);

		static Application& Get() noexcept { return *instance; }
		Window& GetWindow() noexcept { return *window; }

		GameObject& CreateGameObject();


	private:
		bool OnWindowClose(WindowCloseEvent& event);
		bool OnWindowResize(WindowResizeEvent& event);

		void ExeDestroyObjects();
		bool isRunning;
		unsigned int maxFrameRate;
		double lastFrame;

		unsigned int lastGameObjectId = 0;

		std::unique_ptr<SpriteRenderer> spriteRenderer;

		static Application* instance;
		std::unique_ptr<Window> window;

		std::unordered_map<unsigned int, std::unique_ptr<GameObject>> gameObjects;

		std::vector<unsigned int> destroyQueue;
	};

	// To be defined in client
	Application* CreateApplication();
}
