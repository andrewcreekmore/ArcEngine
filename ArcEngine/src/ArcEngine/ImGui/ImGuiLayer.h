#pragma once

#include "ArcEngine/Layer.h"
#include "ArcEngine/Events/ApplicationEvent.h"
#include "ArcEngine/Events/KeyEvent.h"
#include "ArcEngine/Events/MouseEvent.h"

/*
===========================================================================
ImGuiLayer: debug GUI layer
- 
- 
===========================================================================
*/

namespace ArcEngine
{
	class ARCENGINE_API ImGuiLayer : public Layer
	{
	public:

		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void OnDetach();
		void OnUpdate();
		void OnEvent(Event& event);

	private:

		//bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
		//bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
		//bool OnMouseMovedEvent(MouseMovedEvent& e);
		//bool OnMouseScrolledEvent(MouseScrolledEvent& e);
		//bool OnKeyPressedEvent(KeyPressedEvent& e);
		//bool OnKeyReleasedEvent(KeyReleasedEvent& e);
		////bool OnKeyTypedEvent(KeyTypedEvent& e);
		//bool OnWindowResizeEvent(WindowResizeEvent& e);

		void Begin();
		void End();

	private:

		float m_Time = 0.0f;
	};
}