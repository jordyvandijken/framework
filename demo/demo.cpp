// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <glfw3.h>

#include <common/core.h>

#include <common/scene.h>

#include "scene1.h"
#include "scene2.h"
#include "scene3.h"
#include "scene4.h"

int main( void )
{
	std::vector<Scene*> scenes;
	Core* core = new Core();

	Scene1* scene1 = new Scene1();
	Scene2* scene2 = new Scene2();
	Scene3* scene3 = new Scene3();
	Scene4* scene4 = new Scene4();
	scenes.push_back(scene1);
	scenes.push_back(scene2);
	scenes.push_back(scene3);
	scenes.push_back(scene4);
	// show what scene
	int showScene = 3;
	if (!FULLSCREEN) {
		std::cout << "Show scene: " << std::flush;
		std::cin >> showScene;
		showScene--;
		if (showScene < 0 && showScene > scenes.size() - 1){
			showScene = 0;
		}
	}

	// need to show fps in console
	core->setShowFps(SHOWFPS);

	do {
		core->runScene(scenes[showScene]);
	} // Check if the ESC key was pressed or the window was closed
	while(!core->mustQuit());

	delete scene1;
	delete scene2;
	delete scene3;
	delete scene4;
	delete core;
	// Close OpenGL window and terminate GLFW
	Input::deleteInstance();
	ResourceManager::deleteInstance();

	glfwTerminate();

	return 0;
}
