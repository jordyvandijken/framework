/**
* @file scene.h
*
* @brief The Scene header file.
*
* This file is part of a 2D OpenGL framework.
*
* - Copyright 2016 Jordy van Dijken <jordyvandijken@gmail.com>
*   - Initial commit
*/

#ifndef SCENE_H
#define SCENE_H

// Include GLEW
#include <GL/glew.h>

#include <vector>

#include <common/camera.h>
#include <common/entity.h>
#include <common/input.h>
#include <common/resourcemanager.h>

/// @brief The Scene class is the Base class for your own Scenes. It has a Camera and Input.
class Scene {
public:
	Scene(); ///< @brief Constructor of the Scene
	virtual ~Scene(); ///< @brief Destructor of the Scene
	/// @brief update Scene.
	/// @param float deltaTime the number of seconds since the last update
	/// @return void
	virtual void update(float deltaTime) = 0;
	/// @brief add entity to the scene for rendering
	/// @param Entity* entity
	/// @return void
	void addEntity(Entity* _entity);
	/// @brief get a list of entities that are added to the scene
	/// @return std::vector<Entity* >
	std::vector<Entity *> getEntities() {return entities;};

	std::vector<Entity *> entities; ///< @brief scene entities list

	Camera* camera; ///< @brief camera instance

	ResourceManager* resManager;

private:

};

#endif /* SCENE_H */
