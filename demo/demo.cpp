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
	int showScene = 0;
	int _time = 0;

	do {
		core->runScene(scenes[showScene]);
		core->setShowFps(true);
		_time++;
		if (_time == 1000) {
			showScene = 1;
		} else if (_time > 2000) {
			showScene = 0;
			_time = 0;
		}
	} // Check if the ESC key was pressed or the window was closed
	while(!core->mustQuit());

	delete scene1;
	delete scene2;
	delete core;
	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}
