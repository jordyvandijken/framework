#ifndef SCENE1_H
#define SCENE1_H

#include <common/scene.h>
#include <common/entity.h>

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
};

#endif
