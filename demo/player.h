#ifndef PLAYER_H
#define PLAYER_H

#include <common/entity.h>

class Player : public Entity
{
public:
	Player();
	virtual ~Player();

	void update(float deltaTime);

	void updatePos(glm::vec2 _pos);

private:

};

#endif
