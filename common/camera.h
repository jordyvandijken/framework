#ifndef CAMERA_H
#define CAMERA_H

// Include GLFW
#include <glfw3.h>

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>

class Camera {
public:
  Camera ();
  ~Camera ();

  void computeMatricesFromInputs(GLFWwindow* window);
  void setPosition(int _x, int _y);
  void setPosition(glm::vec2 _pos);
  void addPosition(glm::vec2 _pos);

  glm::mat4 getViewMatrix();

  glm::vec3 getMousePosInput() {return glm::vec3(position.x, position.y, 0.0f);};

private:
  glm::mat4 ViewMatrix;

  glm::vec3 position;

  int distance;
};

#endif
