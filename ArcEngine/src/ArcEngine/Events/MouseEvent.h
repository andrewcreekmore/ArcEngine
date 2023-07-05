#pragma once

#include "Event.h"

/*
===========================================================================
MouseEvent.h: mouse-level input Events
- mouse moving/scrolling Events
- mouse button press/release Events
===========================================================================
*/

namespace ArcEngine
{
	class ARCENGINE_API MouseMovedEvent : public Event
	{
	public:

		MouseMovedEvent(float x, float y)
			: m_MouseX(x), m_MouseY() {}

		inline float GetX() const { return m_MouseX; }
		inline float GetY() const { return m_MouseY; }

		// debug info function
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << GetX() << ", " << GetY();
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:

		float m_MouseX, m_MouseY;
	};

	//---------------------------// 

	class ARCENGINE_API MouseScrolledEvent : public Event
	{
	public:

		MouseScrolledEvent(float xOffset, float yOffset)
			: m_XOffset(xOffset), m_YOffset(yOffset) {}

		inline float GetXOffset() const { return m_XOffset; }
		inline float GetYOffset() const { return m_YOffset; }

		// debug info function
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:

		float m_XOffset, m_YOffset;
	};

	//---------------------------// 

	// common base class for all other MouseButtonEvent types
	class ARCENGINE_API MouseButtonEvent : public Event
	{
	public:

		inline int GetMouseButton() const { return m_Button; }

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	protected:

		MouseButtonEvent(int button)
			: m_Button(button) {}

		int m_Button;
	};

	//---------------------------// 

	class ARCENGINE_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button)
			: MouseButtonEvent(button) {}

		// debug info function
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	//---------------------------// 

	class ARCENGINE_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button)
			: MouseButtonEvent(button) {}

		// debug info function
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}