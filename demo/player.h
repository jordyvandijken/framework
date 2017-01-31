#ifndef PLAYER_H
#define PLAYER_H

#include <common/entity.h>

class Player : public Entity
{
public:
	Player();
	virtual ~Player();

	void update(float deltaTime);

	void updatePos(Vector2 _pos);

private:

};

#endif
