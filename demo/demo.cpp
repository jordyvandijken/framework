// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <glfw3.h>

#include <common/core.h>

#include <common/scene.h>

#include "scene1.h"
#include "scene2.h"

int main( void )
{
	std::vector<Scene*> scenes;
	Core* core = new Core();
	Scene1* scene1 = new Scene1();
	Scene2* scene2 = new Scene2();
	scenes.push_back(scene1);
	scenes.push_back(scene2);
	// show what scene
	int showScene = 0;

	// need to show fps in console
	core->setShowFps(true);

	do {
		core->runScene(scenes[showScene]);
	} // Check if the ESC key was pressed or the window was closed
	while(!core->mustQuit());

	delete scene1;
	delete scene2;
	delete core;
	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}
