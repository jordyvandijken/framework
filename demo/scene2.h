#ifndef SCENE2_H
#define SCENE2_H

#include <common/scene.h>
#include <common/entity.h>

#include <demo/player.h>

class Scene2 : public Scene
{
public:
	Scene2();
	virtual ~Scene2();
	void update(float deltaTime);

private:
		Player* player;
};

#endif
