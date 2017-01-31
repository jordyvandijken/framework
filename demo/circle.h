#ifndef CIRCLE_H
#define CIRCLE_H

#include <common/scene.h>

class Circle : public Entity
{
public:
	Circle();
	virtual ~Circle();
	void update(float deltaTime);

private:

};

#endif
