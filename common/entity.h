#ifndef ENTITY_H
#define ENTITY_H

// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>

// Include GLEW
#include <GL/glew.h>

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>

// Include GLFW
#include <glfw3.h>

#include <common/sprite.h>

class Entity
{
public:
	Entity();
	virtual ~Entity();

	virtual void update(float deltaTime) {};

	glm::vec2 position;
	glm::vec2 scale;
	int layer;
	float rotation;
	Entity* parent;


	void addSprite(Sprite* _sprite);
	void addChild(Entity* _child);
	void removeChild(Entity* _child);
	void setPosition(int _x, int _y);
	void setPosition(glm::vec2 _pos);

	std::vector<Entity*> getChildren() {return children;};

	Sprite* getSprite() {return sprite;};
	Entity* getParent() {return parent;};
	Entity* getChild(int _num);
	int getLayer() {return layer;};
	int entityNum() {return _entityNum;};
	glm::vec2 getPosition() {return position;};
	glm::vec2 getScale() {return scale;};
	float getRotation() {return rotation;};

private:
	Sprite* sprite;

	std::vector<Entity*> children;
	int _entityNum;
	static int _nextNum;
};

#endif
