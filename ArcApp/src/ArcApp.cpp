#include "ArcEngine.h"

/*
===========================================================================
ArcApp: skeleton class for ArcEngine client applications
-
-
===========================================================================
*/

class ExampleLayer : public ArcEngine::Layer
{
public:

	ExampleLayer()
		: Layer("Example")
	{

	}

	void OnUpdate() override
	{
		//ARC_INFO("ExampleLayer::Update");

		//if (ArcEngine::Input::IsKeyPressed(ARC_KEY_TAB))
		//	ARC_TRACE("Tab key is pressed!");
	}

	virtual void OnImGuiRender() override
	{

	}

	void OnEvent(ArcEngine::Event& event) override
	{
		//ARC_TRACE("{0}", event.ToString());

		//if (event.GetEventType() == ArcEngine::EventType::KeyPressed)
		//{
		//	ArcEngine::KeyPressedEvent& e = (ArcEngine::KeyPressedEvent&)event;
		//	ARC_TRACE("{0}", (char)e.GetKeyCode());
		//}
	}
};

class ArcApp : public ArcEngine::Application
{
public:

	ArcApp()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new ArcEngine::ImGuiLayer());
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