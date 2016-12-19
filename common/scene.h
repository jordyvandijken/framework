#ifndef SCENE_H
#define SCENE_H

// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <glfw3.h>

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>

#include <common/camera.h>
#include <common/entity.h>
#include <common/input.h>

class Scene
{
public:
	Scene();
	virtual ~Scene();

	virtual void update(float deltaTime) = 0;

	void addEntity(Entity* _entity);

	Camera* camera() {return _camera;};

	std::vector<Entity *> getEntities() {return entities;};

	std::vector<Entity *> entities;

	Camera* _camera;

	Input* input;

private:


};

#endif
