#pragma once

#include "ArcEngine/Core.h"
#include "Layer.h"

//#include <vector>

/*
===========================================================================
LayerStack: an ordered list of Layer objects
- structure determines:
-- a) where an Event is received, and consequently, when it's processed
-- b) in what order various app functions occur (rendering, updating, etc)
- contains both Layers and Overlays (which are also Layers, but always last)
===========================================================================
*/

namespace ArcEngine
{
	class ARCENGINE_API LayerStack
	{
	public:

		LayerStack();
		~LayerStack();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		void PopLayer(Layer* layer);
		void PopOverlay(Layer* overlay);

		std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
		std::vector<Layer*>::iterator end() { return m_Layers.end(); }

	private:

		std::vector<Layer*> m_Layers;
		std::vector<Layer*>::iterator m_LayerInsert;
		//unsigned int m_LayerInsertIndex = 0;
	};
}