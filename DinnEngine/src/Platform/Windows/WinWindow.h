#pragma once
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

		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

	private:
		virtual void Init(const WindowProperties& props);
		virtual void Shutdown();

		GLFWwindow* Window;

		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;
		};

		WindowData data;
	};
}
