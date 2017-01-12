/**
 * @file camera.h
 *
 * @brief The Camera header file.
 *
 * This file is part of a 2D OpenGL framework.
 *
 * - Copyright 2016 Jordy van Dijken <jordyvandijken@gmail.com>
 *   - Initial commit
 */

#ifndef CAMERA_H
#define CAMERA_H

// Include GLFW
#include <glfw3.h>

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>

/// @brief The Camera class is a instance of standard Scene.
class Camera {
public:
  Camera (); ///< @brief Constructor of the Camera
  ~Camera (); ///< @brief Destructor of the Camera
  /// @brief computeMatricesFromInputs.
	/// @param GLFWwindow* window the window that is open
	/// @return void
  void computeMatricesFromInputs(GLFWwindow* window);
  /// @brief set position with two ints.
  /// @param int _x
  /// @param int _y
  /// @return void
  void setPosition(int _x, int _y);
  /// @brief set position with glm::vec2.
  /// @param glm::vec2(x,y)
  /// @return void
  void setPosition(glm::vec2 _pos);
  /// @brief add glm::vec2 to the current position.
  /// @param glm::vec2(x,y)
  /// @return void
  void addPosition(glm::vec2 _pos);
  /// @brief getViewMatrix.
  /// @return mat4
  glm::mat4 getViewMatrix();
  /// @brief get camera position.
  /// @return glm::vec2
  glm::vec2 getPosition() {return glm::vec2(position.x, position.y);};

private:
  glm::mat4 ViewMatrix; ///< @brief ViewMatrix of the Camera

  glm::vec3 position; ///< @brief position of the Camera

};

#endif /* CAMERA_H */
