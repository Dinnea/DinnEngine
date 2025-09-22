#pragma once
#include "DinnCore/Core.h"
#include "DinnCore/Events/Event.h"

namespace Dinn
{
	class DINN_API KeyEvent : public Event
	{
	public:
		int GetKeyCode() const { return keyCode; }

		EVENT_CLASS_FLAGS(EventFlagKeyboard | EventFlagInput)

	protected:
		KeyEvent(int _keyCode) : keyCode(_keyCode) {}
		int keyCode;
	};

	class DINN_API KeyPressEvent : public KeyEvent
	{
	public:
		KeyPressEvent(int _keyCode, bool _repeated) : KeyEvent(_keyCode), repeated(_repeated) {}
		bool IsRepeated() const { return repeated; }

		std::string ToString() const override
		{
			std::stringstream str;
			str << "KeyPressedEvent: " << keyCode << ", repeated? " << repeated;
			return str.str();
		}

		EVENT_CLASS_TYPE(KeyPress)

	private:
		bool repeated;
	};

	class DINN_API KeyReleaseEvent : public KeyEvent
	{
	public:
		KeyReleaseEvent(int _keyCode, bool _repeated) : KeyEvent(_keyCode) {}

		std::string ToString() const override
		{
			std::stringstream str;
			str << "KeyReleasedEvent: " << keyCode;
			return str.str();
		}

		EVENT_CLASS_TYPE(KeyRelease)
	};
}