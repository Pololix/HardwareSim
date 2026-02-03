#pragma once

struct GLFWwindow;

namespace platform {
class Window {
public:
	Window(int width, int height, const char* name);
	~Window();

	void swapBuffers() const;
	void pollEvents() const;
	bool shouldClose() const;

	bool isValid() const;
private:
	GLFWwindow* m_window = nullptr;
};
}