#pragma once
#include "dnpch.h"
#include "Events/Event.h"

namespace Dinn
{
	struct WindowProperties
	{
		std::string Title;
		uint32_t Width;
		uint32_t Height;

		WindowProperties(const std::string& title = "DinnEngine", uint32_t width = 1200, uint32_t height = 900)
			: Title(title), Width(width), Height(height)
		{
		}
	};

	namespace Input {
		enum class Keyboard : int;
		enum class Mouse : int;
	}


	class Window
	{
	public:
		using EventCallback = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void Update() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetEventCallback(const EventCallback& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual bool IsKeyDown(Input::Keyboard key) = 0;
		virtual bool IsMouseDown(Input::Mouse btn)  = 0;

		static Window* Create(const WindowProperties& props = WindowProperties());
	};

}

