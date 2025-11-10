#pragma once
#include "dnpch.h"
#include "AssetManager.h"
#include "Core.h"
#include "Events/WindowEvent.h"
#include "GameObject.h"
#include "Rendering/SpriteRenderer.h"
#include "Time.h"
#include "Window.h"
#include <chrono>
#include <thread>

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

		Window& GetWindow() noexcept  { return *window; }

		AssetManager& GetAssetManager() noexcept { return *assetManager; }

		GameObject& CreateGameObject();


		static Application& Instance() noexcept { return *instance; }


	private:
		bool OnWindowClose(WindowCloseEvent& event);
		bool OnWindowResize(WindowResizeEvent& event);

		bool OnKeyEvent(Event& event);

		void ExeDestroyObjects();
		bool isRunning;
		unsigned int maxFrameRate;
		double lastFrame;

		unsigned int lastGameObjectId = 0;

		std::unique_ptr<Window> window;

		std::unique_ptr<AssetManager> assetManager;

		std::unique_ptr<SpriteRenderer> spriteRenderer;

		std::unordered_map<unsigned int, std::unique_ptr<GameObject>> gameObjects;

		std::vector<unsigned int> destroyQueue;

		static Application* instance;
	};

	// To be defined in client
	Application* CreateApplication();
}
