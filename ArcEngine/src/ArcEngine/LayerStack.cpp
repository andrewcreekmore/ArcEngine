#include "ArcEnginePCH.h"
#include "LayerStack.h"

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
	LayerStack::LayerStack()
	{
		m_LayerInsert = m_Layers.begin();
	}

	LayerStack::~LayerStack()
	{
		for (Layer* layer : m_Layers)
			delete layer;
	}

	//---------------------------// 

	void LayerStack::PushLayer(Layer* layer)
	{
		m_LayerInsert = m_Layers.emplace(m_LayerInsert, layer);
		//m_Layers.emplace(m_Layers.begin() + m_LayerInsertIndex, layer);
		//m_LayerInsertIndex++;
	}

	void LayerStack::PushOverlay(Layer* overlay)
	{
		m_Layers.emplace_back(overlay); // overlays always rendered last
	}

	//---------------------------// 

	void LayerStack::PopLayer(Layer* layer)
	{
		auto it = std::find(m_Layers.begin(), m_Layers.end(), layer);
		if (it != m_Layers.end())
		{
			m_Layers.erase(it);
			m_LayerInsert--;
		}
	}

	void LayerStack::PopOverlay(Layer* overlay)
	{
		auto it = std::find(m_Layers.begin(), m_Layers.end(), overlay);
		if (it != m_Layers.end())
			m_Layers.erase(it);
	}
}