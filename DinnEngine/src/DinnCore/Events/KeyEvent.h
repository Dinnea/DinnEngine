#pragma once
#include "DinnCore/Core.h"
#include "DinnCore/Events/Event.h"
#include "DinnCore/Input.h"

namespace Dinn
{
	class DINN_API KeyEvent : public Event
	{
	public:
		Input::Keyboard GetKeyCode() const { return keyCode; }

		EVENT_CLASS_FLAGS(EventFlagKeyboard | EventFlagInput)

	protected:
		KeyEvent(const Input::Keyboard _keyCode) : keyCode(_keyCode) {}
		Input::Keyboard keyCode;

		Input::Keyboard key;
	};

	class DINN_API KeyPressEvent : public KeyEvent
	{
	public:
		KeyPressEvent(const Input::Keyboard _keyCode, bool _repeated) : KeyEvent(_keyCode), repeated(_repeated) {}
		bool IsRepeated() const { return repeated; }

		std::string ToString() const override
		{

			Input::ToString(keyCode);
			std::stringstream str;
			str << "KeyPressedEvent: " << Input::ToString(keyCode) << ", repeated? " << repeated;
			return str.str();
		}

		EVENT_CLASS_TYPE(KeyPress)

	private:
		bool repeated;
	};

	class DINN_API KeyReleaseEvent : public KeyEvent
	{
	public:
		KeyReleaseEvent(const Input::Keyboard _keyCode) : KeyEvent(_keyCode) {}

		std::string ToString() const override
		{
			std::stringstream str;
			str << "KeyReleasedEvent: " << Input::ToString(keyCode);
			return str.str();
		}

		EVENT_CLASS_TYPE(KeyRelease)
	};
}