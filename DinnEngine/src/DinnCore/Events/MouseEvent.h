#pragma once
#include "DinnCore/Core.h"
#include "DinnCore/Events/Event.h"

namespace Dinn
{
	class DINN_API MouseMovedEvent : public Event
	{
	public:

		MouseMovedEvent(const float x, const float y) : mouseX(x), mouseY(y) {}

		float GetX() const { return mouseX; }
		float GetY() const { return mouseY; }

		std::string ToString() const override
		{
			std::stringstream str;
			str << "MouseMovedEvent: " << mouseX << ", " << mouseY;
			return str.str();
		}

		EVENT_CLASS_TYPE(MouseMove) 
		EVENT_CLASS_FLAGS(EventFlagInput | EventFlagMouse)

	private:
		float mouseX, mouseY;
	};

	class DINN_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(const float x, const float y) : xOffset(x), yOffset(y) {}

		float GetXOffset() const { return xOffset; }
		float GetYOffset() const { return yOffset; }

		std::string ToString() const override
		{
			std::stringstream str;
			str << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
			return str.str();
		}

		EVENT_CLASS_TYPE(MouseScroll) 
		EVENT_CLASS_FLAGS(EventFlagInput | EventFlagMouse)

	private:
		float xOffset, yOffset;
	};

	class DINN_API MouseButtonEvent : public Event
	{
	public:

		Input::Mouse GetMouseButton() const { return button; }

		EVENT_CLASS_FLAGS(EventFlagMouse | EventFlagInput | EventFlagMouseButton)


	protected:
		MouseButtonEvent(const Input::Mouse _button) : button(_button) {}

		Input::Mouse button;
	};

	class DINN_API MouseButtonPressEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressEvent(const Input::Mouse _button) : MouseButtonEvent(_button) {}

		std::string ToString() const override
		{
			std::stringstream str;
			str << "MouseButtonPressedEvent: " << Input::ToString(button);
			return str.str();
		}

		EVENT_CLASS_TYPE(MousePress)
	};

	class DINN_API MouseButtonReleaseEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleaseEvent(const Input::Mouse _button) : MouseButtonEvent(_button) {}

		std::string ToString() const override
		{
			std::stringstream str;
			str << "MouseButtonPressedEvent: " << Input::ToString(button);
			return str.str();
		}

		EVENT_CLASS_TYPE(MouseRelease)
	};
}