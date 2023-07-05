#pragma once

#include "ArcEnginePCH.h"
#include "ArcEngine/Core.h"

/*
===========================================================================
Event.h: general Event base + EventDispatcher classes
- sub-types created by Window when it receives any event with a defined callback fn
- once created, Events back-propagated from Window to Application via its OnEvent() fn
- Events are blocking (i.e., not buffered; dispatched + processed immediately) for now
===========================================================================
*/

namespace ArcEngine
{
	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled

	};

	enum EventCategory // grouping types for ease of filtering
	{
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput		 = BIT(1),
		EventCategoryKeyboard	 = BIT(2),
		EventCategoryMouse		 = BIT(3),
		EventCategoryMouseButton = BIT(4)
	};

	//---------------------------// 

	// macros for ease of implementing event sub-classes
	#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
							virtual EventType GetEventType() const override { return GetStaticType(); }\
							virtual const char* GetName() const override { return #type; }

	#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	//---------------------------// 

	class ARCENGINE_API Event
	{
		friend class EventDispatcher;

	public:

		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;

		// debug info function; by default only returns event name
		virtual std::string ToString() const { return GetName(); }

		// for filtering
		bool IsInCategory(EventCategory category) { return GetCategoryFlags() & category; }

		bool IsHandled() const { return m_Handled; }

	protected:

		bool m_Handled = false;
	};

	//---------------------------// 

	// sends Events to the appropriate function based on their EventType
	class ARCENGINE_API EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;

	public:

		EventDispatcher(Event& event)
			: m_Event(event)
		{
		}

		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			// does the event type match the template argument?
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				// dispatch to appropriate function
				m_Event.m_Handled = func(*(T*)&m_Event);
				return true;
			}

			return false; // do not dispatch
		}

	private:

		Event& m_Event;
	};
}