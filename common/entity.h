/**
 * @file entity.h
 *
 * @brief The Entity header file.
 *
 * This file is part of a 2D OpenGL framework.
 *
 * - Copyright 2016 Jordy van Dijken <jordyvandijken@gmail.com>
 *   - Initial commit
 */

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
#include <common/config.h>
#include <common/vector2.h>

/// @brief The Entity class is a instance of standard Scene.
class Entity {
public:
	Entity(float x = 0.0f, float y = 0.0f); ///< @brief Constructor of the Entity
	virtual ~Entity(); ///< @brief Destructor of the Entity
	/// @brief update Entity.
	/// @param deltaTime the number of seconds since the last update
	/// @return void
	virtual void update(float deltaTime) {};
	/// @brief add Sprite to Entity.
	/// @param sprite of the type Sprite
	/// @return void
	void addSprite(Sprite* _sprite);
	/// @brief add child to Entity.
	/// @param entity of the type Entity
	/// @return void
	void addChild(Entity* _child);
	/// @brief remove child from Entity.
	/// @param entity of the type Entity
	/// @return void
	void removeChild(Entity* _child);
	/// @brief set position with two ints.
	/// @param int x
	/// @param int y
	/// @return void
	void setPosition(int _x, int _y);
	/// @brief set position with glm::vec2.
	/// @param glm::vec2(x,y)
	/// @return void
	void setPosition(Vector2 _pos);
	/// @brief get the layer of the Entity.
	/// @return int - return layer
	int getLayer() {return layer;};
	/// @brief return number of the Entity.
	/// @return int - return Entity number
	int entityNum() {return _entityNum;};
	/// @brief get the rotation of the Entity.
	/// @return float - return rotation
	float getRotation() {return rotation;};
	/// @brief get the Sprite from Entity.
	/// @return Sprite* - pointer to sprite
	Sprite* getSprite() {return sprite;};
	/// @brief get the parent from Entity.
	/// @return Entity* - pointer to parent
	Entity* getParent() {return parent;};
	/// @brief get the child from Entity.
	/// @return Entity* - pointer to child
	Entity* getChild(int _num);
	/// @brief get the position of Entity.
	/// @return glm::vec2(x,y) - return position
	Vector2 getPosition() {return position;};
	/// @brief get the scale of Entity.
	/// @return glm::vec2(scaleX,scaleY) - return scale
 	Vector2 getScale() {return scale;};
	/// @brief get all children of Entity.
	/// @return std::vector<Entity*> - return children
	std::vector<Entity*> getChildren() {return children;};

	Vector2 position; ///< @brief position of the Entity
	Vector2 scale; ///< @brief scale of the Entity

	int layer; ///< @brief layer of the Entity

	float rotation; ///< @brief rotation of the Entity

	Entity* parent; ///< @brief parent of the Entity

	void setWorldPos(Vector2 wp) {worldpos = wp;};

	Vector2 getWorldPosition() {return worldpos;};

	int getWidth() {if (sprite != NULL) {return sprite->getWidth() * scale.x;} else {return 1;};};

	int getHeight() {if (sprite != NULL) {return sprite->getHeight() * scale.y;} else {return 1;};};

	float getRad() {return rotation * DEGTORAD;};

	Vector2 worldpos; ///< Brief position of the Entity in the world

	void scaleToSize(int _x = 0, int _y = 0);

	Vector2 getParentScale();

private:
	Sprite* sprite;  ///< @brief sprite of the Entity

	std::vector<Entity*> children; ///< @brief list of children

	int _entityNum; ///< @brief intity number of the Entity

	static int _nextNum; ///< @brief next number

};

#endif
