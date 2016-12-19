#ifndef CORE_H
#define CORE_H

#include <common/scene.h>
#include <common/renderer.h>
#include <vector>

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
	void showAverageFps();
	bool needToShow;
	std::vector<int> averageFps;
};

#endif
