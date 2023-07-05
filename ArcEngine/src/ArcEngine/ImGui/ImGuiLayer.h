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

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();

	private:

		float m_Time = 0.0f;
	};
}