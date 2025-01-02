#pragma once

extern X::Application* CreatSandbox();

int main(int argc, char* argv[]) {
	printf("welcome to it");
 auto app = CreatSandbox();
 app->Run();
 delete app;
}