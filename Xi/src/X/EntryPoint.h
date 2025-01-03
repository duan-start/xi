#pragma once

#ifdef X_WINDOWS
//extern is to make build done,without linking 
extern X::Application* CreatSandbox();

int main(int argc, char* argv[]) {

	X::Log::Init();
	X_CORE_TRACE("Game Engine");
	X_INFO("Welcome to Xi Engine, client");
	//to create snabox object
	auto app = CreatSandbox();
	app->Run();
	delete app;
}
#endif