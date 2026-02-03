#pragma once 

#include "platform/window.h"

namespace core {
class Application {
public:
	Application(int width, int height, const char* name);
	~Application();

	void swapBuffers() const;
	void pollEvents() const;
	bool shouldClose() const;
private:
	platform::Window m_window;
};
}