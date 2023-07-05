#include "ArcEnginePCH.h"
#include "Application.h"
//#include "Input.h"

//#include <glad/glad.h>

/*
===========================================================================
Application: central hub class; wrapper for clients (ArcApps)
- creates Window
- receives Events (from Window) and dispatches them to Layers
- Run() loop updates app
- singleton
===========================================================================
*/

namespace ArcEngine 
{
	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		ARC_CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(ARC_BIND_EVENT_FN(Application::OnEvent));
	}


	Application::~Application()
	{

	}

	//---------------------------// 

	void Application::Run()
	{
		while (m_Running)
		{
			// update each layer/overlay in the layer stack
			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();

			//auto [xPos, yPos] = Input::GetMousePosition();
			//ARC_CORE_TRACE("{0}, {1}", xPos, yPos);

			m_Window->OnUpdate();
		}
	}

	void Application::OnEvent(Event& e)
	{
		//ARC_CORE_INFO("{0}", e.ToString());

		EventDispatcher dispatcher(e);
		// if event is a WindowClose (Dispatch checks type), call OnWindowClose()
		dispatcher.Dispatch<WindowCloseEvent>(ARC_BIND_EVENT_FN(Application::OnWindowClose));

		// traverse backwards through the layer stack, calling OnEvent, until event handled
		// -- if an overlay handles an event, the layers will not receive it
		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); )
		{
			(*--it)->OnEvent(e);
			if (e.IsHandled())
				break;
		}
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* overlay)
	{
		m_LayerStack.PushOverlay(overlay);
		overlay->OnAttach();
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}
}
