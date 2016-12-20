// Include GLFW
#include <glfw3.h>

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;

#include "camera.h"

Camera::Camera() {
	// Initial position : on +Z
	position = glm::vec3( 0, 0, 5 );
}

glm::mat4 Camera::getViewMatrix() {
	return ViewMatrix;
}

void Camera::setPosition(int _x, int _y) {
	this->position = glm::vec3(_x, _y, 5);
}

void Camera::setPosition(glm::vec2 _pos) {
	this->position = glm::vec3(_pos.x, _pos.y, 5);
}

void Camera::addPosition(glm::vec2 _pos) {
	this->position += glm::vec3(_pos.x, _pos.y, 0.0f);
}

void Camera::computeMatricesFromInputs(GLFWwindow* window) {
	this->position.z = 5;
	// View matrix
	ViewMatrix = glm::lookAt(
			position, // Camera is at (xpos,ypos,5), in World Space
			position + glm::vec3(0, 0, -5), // and looks towards Z
			glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
			);
}

Camera::~Camera (){

}
