#include "ArcEngine.h"

#include "ImGui/imgui.h"

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

	}

	virtual void OnImGuiRender() override
	{

	}

	void OnEvent(ArcEngine::Event& event) override
	{
		//ARC_TRACE("{0}", event.ToString());
	}
};

class ArcApp : public ArcEngine::Application
{
public:

	ArcApp()
	{

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