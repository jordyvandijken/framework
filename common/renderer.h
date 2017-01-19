/**
 * @file renderer.h
 *
 * @brief The Renderer header file.
 *
 * This file is part of a 2D OpenGL framework.
 *
 * - Copyright 2016 Jordy van Dijken <jordyvandijken@gmail.com>
 *   - Initial commit
 */

#ifndef RENDERER_H
#define RENDERER_H

// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <string>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <glfw3.h>

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>
using namespace glm;

#include <common/shader.h>
#include <common/scene.h>
#include <common/config.h>

/// @brief The Camera class is a instance of standard Scene.
class Renderer {
public:
	Renderer(); ///< @brief Constructor of the Camera
	virtual ~Renderer(); ///< @brief Destructor of the Camera
	/// @brief runs the scene.
	/// @param Scene* scene the scene that you want to run
	/// @param float deltaTime the number of seconds since the last update
	/// @return void
	void run(Scene* scene, float deltaTime);
	/// @brief render entity.
	/// @param glm::mat4 modelMatrix
	/// @param Entity* entity
	/// @return void
	void renderEntity(glm::mat4 &modelMatrix, Entity* entity);
	/// @brief set screen size.
	/// @param int width
	/// @param int height
	/// @param bool fullScreen
	/// @return void
	void setScreenSize(int _sWidth, int _sHeight,bool _wanted_fullScreen);
	/// @brief calculate the model matrix.
	/// @param glm::vec2 position
	/// @param glm::vec2 scale
	/// @param float rotation
	/// @return glm::mat4 - return modelMatrix
	glm::mat4 getModelMatrix(Entity* _entity);
	/// @brief get window.
	/// @return GLFWwindow*
	GLFWwindow* getWindow() { return window; };
	/// @brief need to quit.
	/// @return bool - need to quit (true / false)
	bool mustQuit();

	bool _debug;

private:
	Scene* scene; ///< @brief instance of renderer

	GLFWwindow* window; ///< @brief window of renderer

	int window_width; ///< @brief int window width
	int window_height; ///< @brief int window height

	bool fullScreen; ///< @brief bool fullScreen

	std::string fragment_shader; ///< @brief string fragment_shader
	std::string vertex_shader; ///< @brief string vertex_shader

	glm::mat4 projectionMatrix; ///< @brief projection matrix

	GLuint programID; ///< @brief programID
	GLuint matrixID; ///< @brief matrixID
	GLuint vertexPosition_modelspaceID; ///< @brief vertexPosition_modelspaceID
	GLuint vertexUVID; ///< @brief vertexUVID
	GLuint texture;	///< @brief texture
	GLuint textureID; ///< @brief textureID
	/// @brief create windows.
	/// @return int
	int initGL();
	/// @brief swaps buffers.
	/// @return void
	void swapBuffers();

	bool testCulling(Entity* _entity);

};

#endif /* RENDERER_H */
