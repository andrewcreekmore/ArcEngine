#include "ArcEnginePCH.h"
#include "Layer.h"

/*
===========================================================================
Layer: abstract base class; distinct "section" of application
- represents one (1) element of a larger, ordered LayerStack
- allows separation of Event, render, and update processing
===========================================================================
*/

namespace ArcEngine
{
	Layer::Layer(const std::string& debugName /*= "Layer"*/)
		: m_DebugName(debugName)
	{
	}

	Layer::~Layer()
	{
	}
}