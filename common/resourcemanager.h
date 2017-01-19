/**
 * @file resourcemanager.h
 *
 * @brief The ResourceManager header file.
 *
 * This file is part of a 2D OpenGL framework.
 *
 * - Copyright 2016 Jordy van Dijken <jordyvandijken@gmail.com>
 *   - Initial commit
 */

#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <iostream>
#include <string>
#include <map>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <glfw3.h>

#include <common/config.h>
#include <common/sprite.h>
#include <common/shader.h>

class ResourceManager
{
public:
	virtual ~ResourceManager(); ///< @brief Destructor of the ResourceManager
	static void deleteInstance() { if(instance){ delete instance; }; } ///< @brief delete this instance
	/// @brief get a Texture
	/// @param filename the path to the TGA file
	/// @param filter the filtering of the Texture
	/// @param wrap the UV wrapping of the Texture
	/// @return Sprite* a pointer to a Sprite, created from an image file (.tga only).
	static Sprite* getSprite(const std::string& filename, int _sprite_width = 128, int _sprite_height = 128) { return getInstance()->_getSprite(filename, _sprite_width, _sprite_height); };
	Sprite* _getSprite(const std::string& filename, int _sprite_width = 128, int _sprite_height = 128);

	static ResourceManager* getInstance();

private:
	ResourceManager(); ///< @brief Constructor of the ResourceManager

	static ResourceManager* instance;

	/// @brief delete a Sprite from memory
	/// @param filename the name this Sprite is known by
	/// @return void
	void deleteSprite(const std::string& filename);
	/// @brief clean up resources
	/// @return void
	void cleanUp();


	std::map<std::string, Sprite*> _sprites; ///< @brief a map of sprites
};

#endif
