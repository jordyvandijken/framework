#ifndef SCENE1_H
#define SCENE1_H

#include <common/scene.h>

class Scene1 : public Scene
{
public:
	Scene1();
	virtual ~Scene1();
	void update(float deltaTime);

private:
		Entity* test;

		bool flip;
		bool _flip;

		Sound* s;
		Sound* click;
};

#endif
