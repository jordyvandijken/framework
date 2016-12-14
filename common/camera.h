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
  void setPosition(glm::vec3 _pos);

  glm::mat4 getViewMatrix();

  glm::vec3 getCursor();

private:
  glm::mat4 ViewMatrix;

  glm::vec3 position;
  glm::vec3 cursor;

  int distance;
};


#endif
