#include "platform/window.h"

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace platform {
Window::Window(int width, int height, const char* name) 
{
	if (!glfwInit()) {
		std::cout << "couldnt init glfw\n";
		return;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); for macOS

	m_window = glfwCreateWindow(width, height, name, nullptr, nullptr);
	if (!m_window) {
		std::cout << "couldnt create a glfw window\n";
		glfwTerminate();
		return;
	}

	glfwMakeContextCurrent(m_window);
	
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cerr << "couldnt init glad\n";
		return;
	}
}

Window::~Window() 
{
	if (m_window) 
	{
		glfwDestroyWindow(m_window);
		glfwTerminate();
	}
}

bool Window::isValid() const
{
	return m_window;
}

void Window::swapBuffers() const 
{
	glfwSwapBuffers(m_window);
}

void Window::pollEvents() const 
{
	glfwPollEvents();
}

bool Window::shouldClose() const 
{
	return glfwWindowShouldClose(m_window);
}
}