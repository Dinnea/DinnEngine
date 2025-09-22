#pragma once
#include "DinnCore/Events/Event.h"

namespace Dinn
{
	class DINN_API WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(const unsigned int _width, const unsigned int _height)
			: width(_width), height(_height) {
		}

		unsigned int GetWidth() const { return width; }
		unsigned int GetHeight() const { return height; }

		std::string ToString() const override
		{
			std::stringstream str;
			str << "WindowResizeEvent: " << width << ", " << height;
			return str.str();
		}

		EVENT_CLASS_TYPE(WindowResize) EVENT_CLASS_FLAGS(EventFlagApplication)

	private:
		unsigned int width, height;
	};

	class DINN_API WindowClose : public Event
	{
	public:

		EVENT_CLASS_TYPE(WindowClose) EVENT_CLASS_FLAGS(EventFlagApplication)

	};
}