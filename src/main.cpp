#include "core/application.h"

int main() 
{
	core::Application app(600, 600, "name");

	while (!app.shouldClose()) 
	{

		app.swapBuffers();
		app.pollEvents();
	}
}