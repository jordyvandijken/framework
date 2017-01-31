#ifndef SCENE5_H
#define SCENE5_H

// include scene
#include <common/scene.h>

//include your own classes
#include <demo/circle.h>
#include <demo/circlepoint.h>

class Scene5 : public Scene
{
public:
	Scene5();
	virtual ~Scene5();
	void update(float deltaTime);

private:
	Entity* rotatePoint;
	Circle* circle;
	float rotateSpeed;

	Circlepoint* circlepoint;

	Entity* bar;

	Vector2* dis;

	Entity* background;

	bool alive;

	bool active;

	int points;

	float barScale;
};

#endif
