#ifndef SCENE4_H
#define SCENE4_H

#include <common/scene.h>
#include <common/entity.h>

class Scene4 : public Scene
{
public:
	Scene4();
	virtual ~Scene4();
	void update(float deltaTime);

private:
   std::vector<Entity*> entitiesList;
};

#endif
