#pragma once

#include "Core.h"

//#include "Events/ApplicationEvent.h"
//#include "Events/Event.h"
//#include "Engine/LayerStack.h"
//#include "Engine/Log.h"
//#include "Window.h"

/*
===========================================================================
Application: 
- 
- 
===========================================================================
*/


namespace ArcEngine
{
	class ARCENGINE_API Application
	{
	public:

		Application();
		virtual ~Application();

		void Run();

		//void OnEvent(Event& e);

		//void PushLayer(Layer* layer);
		//void PushOverlay(Layer* overlay);

		inline static Application& Get() { return *s_Instance; }
		//inline Window& GetWindow() { return *m_Window; }

	private:

		//bool OnWindowClose(WindowCloseEvent& e);

		//std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		//LayerStack m_LayerStack;

		static Application* s_Instance;
	};

	// to be defined in client (i.e., ArcApp) and called in EntryPoint
	Application* CreateApplication();
}

