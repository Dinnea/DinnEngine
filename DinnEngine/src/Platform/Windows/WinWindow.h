#pragma once
#include "DinnCore/Window.h"
#include "DinnCore/Events/Events.h"

//Forward declare window to avoid including GLFW
struct GLFWwindow;

namespace Dinn
{
	class WinWindow : public Window
	{

	public:
		WinWindow(const WindowProperties& props);
		virtual ~WinWindow();

		void Update() override;

		inline unsigned int GetWidth() const override { return data.Width; }
		inline unsigned int GetHeight() const override { return data.Height; }

		inline void SetEventCallback(const EventCallback& callback) override { data.EventCallback = callback; }

		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

		bool IsKeyDown(Input::Keyboard key) override;
		bool IsMouseDown(Input::Mouse key) override;

	private:
		virtual void Init(const WindowProperties& props);
		virtual void Shutdown();

		GLFWwindow* Window;

		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallback EventCallback;
		};

		WindowData data;

		static WindowData& GrabWindowData(GLFWwindow* window);
	};
}
