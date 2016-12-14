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


class Sprite
{
public:
	Sprite(std::string image_path, int sprite_width, int sprite_height);
	virtual ~Sprite();

	// return vertexbuffer
	GLuint getVertexbuffer() {return vertexbuffer;};
	// return uvbuffer
	GLuint getUvbuffer() {return uvbuffer;};
	// return texture
	GLuint getTexture() {return texture;};

	// Load a .tga file using our custom loader
	GLuint loadTGA(const std::string& imagepath);

private:
	GLuint vertexbuffer;
	GLuint uvbuffer;
	GLuint texture;
};

#endif
