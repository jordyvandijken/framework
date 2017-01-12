/**
 * @file sprite.h
 *
 * @brief The Sprite header file.
 *
 * This file is part of a 2D OpenGL framework.
 *
 * - Copyright 2016 Jordy van Dijken <jordyvandijken@gmail.com>
 *   - Initial commit
 */

#ifndef SPRITE_H
#define SPRITE_H

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

/// @brief The Sprite class holds the texture
class Sprite
{
public:
	/// @brief Constructor of the Camera
	/// @param std::string image path
	/// @param int sprite width
	/// @param int sprite height
	Sprite(std::string image_path, int sprite_width, int sprite_height);
	virtual ~Sprite(); ///< @brief Destructor of the Camera
	/// @brief get Vertexbuffer.
	/// @return GLuint - return vertexbuffer
	GLuint getVertexbuffer() {return vertexbuffer;};
	/// @brief get uvbuffer.
	/// @return GLuint - return uvbuffer
	GLuint getUvbuffer() {return uvbuffer;};
	/// @brief get texture.
	/// @return GLuint - return texture
	GLuint getTexture() {return texture;};
	/// @brief load tga.
	/// @param std::string image path
	/// @return GLuint - return texture
	GLuint loadTGA(const std::string& imagepath);

private:
	GLuint vertexbuffer; ///< @brief vertexbuffer
	GLuint uvbuffer; ///< @brief uvbuffer
	GLuint texture; ///< @brief texture
};

#endif /* CAMERA_H */
