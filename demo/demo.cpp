// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <glfw3.h>

#include <common/core.h>

#include "scene1.h"

int main( void )
{
	Core* core = new Core();
	Scene1* scene1 = new Scene1();

	do {
		core->runScene(scene1);
		//core->setShowFps(true);
	} // Check if the ESC key was pressed or the window was closed
	while(!core->mustQuit());

	delete scene1;
	delete core;
	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}
