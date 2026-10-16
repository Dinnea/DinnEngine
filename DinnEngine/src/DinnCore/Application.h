#pragma once
#include "dnpch.h"
#include "AssetManager.h"
#include "Core.h"
#include "Events/WindowEvent.h"
#include "GameObject.h"
#include "Rendering/SpriteRenderer.h"
#include "Window.h"

#include "SceneManager.h"

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
		
		SceneManager& GetSceneManager() noexcept { return *sceneManager; }

		GameObject& CreateGameObject();


		static Application& Instance() noexcept { return *instance; }
		
		static unsigned int GenerateGameObjectId() { return lastGameObjectId++; }

	protected:
		std::unique_ptr<Window> window;

		std::unique_ptr<AssetManager> assetManager;
		
		std::unique_ptr<SceneManager> sceneManager;

		std::unique_ptr<SpriteRenderer> spriteRenderer;

	private:
		bool OnWindowClose(WindowCloseEvent& event);
		bool OnWindowResize(WindowResizeEvent& event);

		bool OnKeyEvent(Event& event);

		void ExeDestroyObjects();
		

		std::unordered_map<unsigned int, std::unique_ptr<GameObject>> gameObjects;

		std::vector<unsigned int> destroyQueue;
		
		double lastFrame;
		unsigned int maxFrameRate;
		bool isRunning;


		static Application* instance;
		inline static unsigned int lastGameObjectId = 0;
	};

	// To be defined in client
	Application* CreateApplication();
}
