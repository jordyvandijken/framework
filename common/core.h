#ifndef CORE_H
#define CORE_H

#include <common/scene.h>
#include <common/renderer.h>

class Core
{
public:
	Core();
	virtual ~Core();

	void runScene(Scene* _scene);
	void setShowFps(bool _c);

	bool mustQuit();

private:
	Renderer* renderer;
	float deltaTime;
	void calcDeltatime();
	void showFps();
	bool needToShow;
};

#endif
