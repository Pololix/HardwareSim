#include "core/application.h"

namespace core 
{
Application::Application(int width, int height, const char* name)
	: m_window(width, height, name) 
{
	if (!m_window.isValid()) 
	{
		this->~Application();
	}
}

Application::~Application()
{

}

void Application::swapBuffers() const 
{
	m_window.swapBuffers();
}

void Application::pollEvents() const 
{
	m_window.pollEvents();
}

bool Application::shouldClose() const 
{
	return m_window.shouldClose();
}
}