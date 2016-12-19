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
#include <common/texture.h>
#include <common/scene.h>
#include <common/config.h>

class Renderer
{
public:
	Renderer();
	virtual ~Renderer();

	void run(Scene* scene, float deltaTime);
	void renderEntity(glm::mat4 &modelMatrix, Entity* entity);
	void setScreenSize(int _sWidth, int _sHeight,bool _wanted_fullScreen);

	glm::mat4 getModelMatrix(glm::vec2 pos, glm::vec2  scal, float rot);

	GLFWwindow* getWindow() { return window; };

	bool mustQuit();

private:
	Scene* scene;

	GLFWwindow* window;

	int window_width;
	int window_height;

	bool fullScreen;

	std::string fragment_shader;
	std::string vertex_shader;

	int initGL();

	void swapBuffers();

	glm::mat4 projectionMatrix;

	GLuint programID;
	GLuint matrixID;
	GLuint vertexPosition_modelspaceID;
	GLuint vertexUVID;
	GLuint texture;
	GLuint textureID;

};

#endif
