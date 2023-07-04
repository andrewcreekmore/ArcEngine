#include <ArcEngine.h>

/*
===========================================================================
ArcApp: skeleton class for ArcEngine client applications
-
-
===========================================================================
*/

class ArcApp : public ArcEngine::Application
{
public:

	ArcApp()
	{
		//PushLayer(new ExampleLayer());
		//PushOverlay(new ArcEngine::ImGuiLayer());
	}

	~ArcApp()
	{

	}

};

//---------------------------// 

ArcEngine::Application* ArcEngine::CreateApplication()
{
	return new ArcApp();
}