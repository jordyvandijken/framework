// Include GLFW
#include <glfw3.h>

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;

#include "camera.h"

Camera::Camera () {
	// Initial position : on +Z
	position = glm::vec3( 0, 0, 5 );
	cursor = glm::vec3( 0, 0, 0 );

	distance = 5;
}

glm::mat4 Camera::getViewMatrix(){
	return ViewMatrix;
}

glm::vec3 Camera::getCursor(){
	return cursor;
}

void Camera::setPosition(int _x, int _y) {
	this->position = glm::vec3(_x, _y, distance);
}

void Camera::setPosition(glm::vec3 _pos){
	this->position = _pos;
}

void Camera::computeMatricesFromInputs(GLFWwindow* window)
{
	// Get mouse position
	double xpos, ypos;
	glfwGetCursorPos(window, &xpos, &ypos);
	cursor = glm::vec3( xpos, ypos, 0 );

	this->position.z = distance;
	// View matrix
	ViewMatrix = glm::lookAt(
			position, // Camera is at (xpos,ypos,5), in World Space
			position + glm::vec3(0, 0, -5), // and looks towards Z
			glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
			);

	cursor.x += position.x;
	cursor.y += position.y;
}

Camera::~Camera (){

}
