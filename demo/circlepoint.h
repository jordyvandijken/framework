#ifndef CIRCLEPOINT_H
#define CIRCLEPOINT_H

#include <common/scene.h>

class Circlepoint : public Entity
{
public:
	Circlepoint();
	virtual ~Circlepoint();
	void update(float deltaTime);

	bool getChanged() {return changed; };

	void setChanged() {changed = false; };

	void addSpeed(float sp) {scaleSpeed += sp;};

	Vector2 oldPos;

	bool active;

private:
	float scaleSpeed;

	bool changed;

};

#endif
