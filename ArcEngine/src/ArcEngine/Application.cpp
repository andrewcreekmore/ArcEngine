//#include "ArcEnginePCH.h"
#include "Application.h"
//#include "Input.h"

//#include <glad/glad.h>

/*
===========================================================================
Application:
-
-
===========================================================================
*/

namespace ArcEngine 
{
	// hold singleton of application
	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		//ARC_CORE_ASSERT(!s_Instance, "Application already exists!");
		//s_Instance = this;

		//m_Window = std::unique_ptr<Window>(Window::Create());
		//m_Window->SetEventCallback(ENG_BIND_EVENT_FN(Application::OnEvent));
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
			//for (Layer* layer : m_LayerStack)
			//	layer->OnUpdate();

			//auto [xPos, yPos] = Input::GetMousePosition();
			//ENG_CORE_TRACE("{0}, {1}", xPos, yPos);

			//m_Window->OnUpdate();
		}
	}

	//void Application::OnEvent(Event& e)
	//{
	//	EventDispatcher dispatcher(e);
	//	dispatcher.Dispatch<WindowCloseEvent>(ENG_BIND_EVENT_FN(Application::OnWindowClose));

	//	// traverse backwards through the layer stack, calling OnEvent, until reaching a handled event
	//	for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); )
	//	{
	//		(*--it)->OnEvent(e);
	//		if (e.IsHandled())
	//			break;
	//	}
	//}

	//void Application::PushLayer(Layer* layer)
	//{
	//	m_LayerStack.PushLayer(layer);
	//	layer->OnAttach();
	//}

	//void Application::PushOverlay(Layer* overlay)
	//{
	//	m_LayerStack.PushOverlay(overlay);
	//	overlay->OnAttach();
	//}

	//bool Application::OnWindowClose(WindowCloseEvent& e)
	//{
	//	m_Running = false;
	//	return true;
	//}
}
