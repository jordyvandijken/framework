#ifndef SCENE3_H
#define SCENE3_H

#include <common/scene.h>
#include <common/entity.h>

class Scene3 : public Scene
{
public:
	Scene3();
	virtual ~Scene3();
	void update(float deltaTime);

private:
	Entity* test;
	Entity* _test3;
	Entity* _test4;
	Entity* _test5;
	Entity* _test6;
	Entity* _test7;
};

#endif
