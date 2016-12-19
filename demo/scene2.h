#ifndef SCENE2_H
#define SCENE2_H

#include <common/scene.h>
#include <common/entity.h>

class Scene2 : public Scene
{
public:
	Scene2();
	virtual ~Scene2();
	void update(float deltaTime);

private:
		Entity* test;

		bool _flip;
};

#endif
