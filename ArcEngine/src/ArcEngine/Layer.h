#pragma once

#include "ArcEngine/Core.h"
#include "ArcEngine/Events/Event.h"

/*
===========================================================================
Layer: abstract base class; distinct "section" of application
- represents one (1) element of a larger, ordered LayerStack
- allows separation of Event, render, and update processing
===========================================================================
*/

namespace ArcEngine
{
	class ARCENGINE_API Layer
	{
	public:

		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		// called when layer is pushed onto LayerStack
		virtual void OnAttach() {}

		// called when layer is popped from LayerStack
		virtual void OnDetach() {}

		// called when layer is updated (i.e., every frame)
		virtual void OnUpdate() {}

		// called when ImGui renders
		//virtual void OnImGuiRender() {}

		// when an event is sent to the layer, it's received here
		virtual void OnEvent(Event& event) {}

		// not to be used for lookup: strictly for debug
		inline const std::string& GetName() const { return m_DebugName; }

	protected:

		// layer name for debugging purposes
		std::string m_DebugName;
	};

}