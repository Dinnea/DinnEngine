#pragma once
#include "Dinn.h"
#include "DinnCore/Window.h"
#include "GLFW/glfw3.h"

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

		static WindowData& GrabWindowData(GLFWwindow* window) { return *static_cast<WindowData*>(glfwGetWindowUserPointer(window)); }
	};
}
