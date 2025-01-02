
#include <X.h>

	class Sandbox :public X::Application {
	public:
		~Sandbox() {};
		Sandbox() {};
	};

	X::Application* CreatSandbox() {
			return new Sandbox();
		}