#pragma once

/*
===========================================================================
EntryPoint.h: engine + client app initialization
- runs ArcEngine startup processes
- creates, runs, and deletes client ArcApp
===========================================================================
*/

#ifdef ARC_PLATFORM_WINDOWS

// an implementation of ArcEngine's Application creation 
// function, to be defined in the client app - (ArcApp.cpp)
extern ArcEngine::Application* ArcEngine::CreateApplication();

int main(int argc, char** argv)
{
	//Engine::Log::Init();
	//ENG_CORE_WARN("Initialized core logger!");
	//int a = 5;
	//ENG_INFO("Initialized client logger! Var = {0}", a);

	auto app = ArcEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif