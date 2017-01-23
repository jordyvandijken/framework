/**
 * This file is part of a 2D OpenGL framework.
 *
 * - Copyright 2015 Jordy van Dijken <jordyvandijken@gmail.com>
 *   - Initial commit
 */

#include <iostream>
#include <common/input.h>

Input* Input::instance = NULL;
Input::Input()
{
	_window = NULL;

	_windowWidth = 0;
	_windowHeight = 0;

	int i;
	for(i=0; i<GLFW_KEY_LAST; i++) {
		_keys[i] = false;
		_keysUp[i] = false;
		_keysDown[i] = false;
	}
	for(i=0; i<GLFW_MOUSE_BUTTON_LAST; i++) {
		_mouse[i] = false;
		_mouseUp[i] = false;
		_mouseDown[i] = false;
	}

	cursor = glm::vec3(0, 0, 0);
}

Input* Input::getInstance() {
	if (!instance) {
		Input::instance = new Input();
	}
	return Input::instance;
}

void Input::_updateInput(GLFWwindow* w ,Camera* c) {
	_window = w;

	glfwPollEvents();

	//  window size
	glfwGetWindowSize(_window, &_windowWidth, &_windowHeight);

	glfwGetCursorPos(_window, &_mouseX, &_mouseY);

	// Fix cursor position if window size is different from the set resolution
	cursor.x = ((float)SWIDTH / _windowWidth) * _mouseX + c->getPosition().x;
	cursor.y = ((float)SHEIGHT / _windowHeight) * _mouseY + c->getPosition().y;

	// 32-97 = ' ' to '`'
	int i;
	for(i=32; i<97;i++) {
		_handleKey(i);
	}
	// Func + arrows + esc, etc
	for(i=255; i<GLFW_KEY_LAST;i++) {
		_handleKey(i);
	}

	// mouse buttons
	for(i=0; i<GLFW_MOUSE_BUTTON_LAST;i++) {
		_handleMouse(i);
	}
}

void Input::_handleMouse(int button)
{
	if (glfwGetMouseButton( _window, button ) == GLFW_PRESS) {
		if (_mouse[button] == false) {
			_mouse[button] = true;
			_mouseDown[button] = true;
		} else {
			_mouseDown[button] = false;
		}
	}
	if (glfwGetMouseButton( _window, button ) == GLFW_RELEASE) {
		if (_mouse[button] == true) {
			_mouse[button] = false;
			_mouseUp[button] = true;
		} else {
			_mouseUp[button] = false;
		}
	}
}

void Input::_handleKey(int key)
{
	if (glfwGetKey( _window, key ) == GLFW_PRESS) {
		if (_keys[key] == false) {
			_keys[key] = true;
			_keysDown[key] = true;
		} else {
			_keysDown[key] = false;
		}
	}
	if (glfwGetKey( _window, key ) == GLFW_RELEASE) {
		if (_keys[key] == true) {
			_keys[key] = false;
			_keysUp[key] = true;
		} else {
			_keysUp[key] = false;
		}
	}
}

Input::~Input() {
}
