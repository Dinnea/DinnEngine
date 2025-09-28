#pragma once
#include "DinnCore/Core.h"
#include "dnpch.h"

namespace Dinn
{
	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		KeyPress, KeyRelease,
		MousePress, MouseRelease, MouseMove, MouseScroll,
	};

	enum EventFlag {
		None = 0,
		EventFlagInput = BIT(0),
		EventFlagKeyboard = BIT(1),
		EventFlagMouse = BIT(2),
		EventFlagMouseButton = BIT(3),
		EventFlagApplication = BIT(4),
	};

	class DINN_API Event
	{

	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetEventFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool HasFlag(EventFlag flag) const { return GetEventFlags() & flag; }
		bool handled = false;
	};

#define EVENT_CLASS_TYPE(type)	static EventType GetStaticType() { return EventType::type; }\
								virtual EventType GetEventType() const override  { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_FLAGS(flag) virtual int GetEventFlags() const override {return flag;}

	class EventDispatcher
	{
		template<typename T>
		using EventFunc = std::function<bool(T&)>;

	public:
		EventDispatcher(Event& _event) : event(_event) {}

		template<typename T>
		bool Dispatch(EventFunc<T> func)
		{
			if (event.GetEventType() != T::GetStaticType())
				return false;

			event.handled |= func(static_cast<T&>(event));
			return true;
		}

	private:
		Event& event;

	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}
}
