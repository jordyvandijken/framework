#ifndef INPUT_H
#define INPUT_H

// Include GLFW
#include <glfw3.h>

// Include glm
#include <glm/glm.hpp>

#include <common/config.h>
#include <common/camera.h>

#define 	GLFW_KEY_UNKNOWN   -1
#define 	KEY_SPACE   GLFW_KEY_SPACE
#define 	KEY_APOSTROPHE   GLFW_KEY_APOSTROPHE
#define 	KEY_COMMA   GLFW_KEY_COMMA
#define 	KEY_MINUS   GLFW_KEY_MINUS
#define 	KEY_PERIOD   GLFW_KEY_PERIOD
#define 	KEY_SLASH   GLFW_KEY_SLASH
#define 	KEY_0   GLFW_KEY_0
#define 	KEY_1   GLFW_KEY_1
#define 	KEY_2   GLFW_KEY_2
#define 	KEY_3   GLFW_KEY_3
#define 	KEY_4   GLFW_KEY_4
#define 	KEY_5   GLFW_KEY_5
#define 	KEY_6   GLFW_KEY_6
#define 	KEY_7   GLFW_KEY_7
#define 	KEY_8   GLFW_KEY_8
#define 	KEY_9   GLFW_KEY_9
#define 	KEY_SEMICOLON   GLFW_KEY_SEMICOLON // ;
#define 	KEY_EQUAL   GLFW_KEY_EQUAL // =
#define 	KEY_A   GLFW_KEY_A
#define 	KEY_B   GLFW_KEY_B
#define 	KEY_C   GLFW_KEY_C
#define 	KEY_D   GLFW_KEY_D
#define 	KEY_E   GLFW_KEY_E
#define 	KEY_F   GLFW_KEY_F
#define 	KEY_G   GLFW_KEY_G
#define 	KEY_H   GLFW_KEY_H
#define 	KEY_I   GLFW_KEY_I
#define 	KEY_J   GLFW_KEY_J
#define 	KEY_K   GLFW_KEY_K
#define 	KEY_L   GLFW_KEY_L
#define 	KEY_M   GLFW_KEY_M
#define 	KEY_N   GLFW_KEY_N
#define 	KEY_O   GLFW_KEY_O
#define 	KEY_P   GLFW_KEY_P
#define 	KEY_Q   GLFW_KEY_Q
#define 	KEY_R   GLFW_KEY_R
#define 	KEY_S   GLFW_KEY_S
#define 	KEY_T   GLFW_KEY_T
#define 	KEY_U   GLFW_KEY_U
#define 	KEY_V   GLFW_KEY_V
#define 	KEY_W   GLFW_KEY_W
#define 	KEY_X   GLFW_KEY_X
#define 	KEY_Y   GLFW_KEY_Y
#define 	KEY_Z   GLFW_KEY_Z
#define 	KEY_Z   GLFW_KEY_Z
#define 	KEY_LEFT_BRACKET   GLFW_KEY_LEFT_BRACKET // [
#define 	KEY_BACKSLASH   GLFW_KEY_BACKSLASH /* \ */
#define 	KEY_RIGHT_BRACKET   GLFW_KEY_RIGHT_BRACKET // ]
#define 	KEY_GRAVE_ACCENT   GLFW_KEY_GRAVE_ACCENT // `
#define 	KEY_WORLD_1   GLFW_KEY_WORLD_1 // non-US #1
#define 	KEY_WORLD_2   GLFW_KEY_WORLD_2 // non-US #2
#define 	KEY_ESCAPE   GLFW_KEY_ESCAPE
#define 	KEY_ENTER   GLFW_KEY_ENTER
#define 	KEY_TAB   GLFW_KEY_TAB
#define 	KEY_BACKSPACE   GLFW_KEY_BACKSPACE
#define 	KEY_INSERT   GLFW_KEY_INSERT
#define 	KEY_DELETE   GLFW_KEY_DELETE
#define 	KEY_RIGHT   GLFW_KEY_RIGHT
#define 	KEY_LEFT   GLFW_KEY_LEFT
#define 	KEY_DOWN   GLFW_KEY_DOWN
#define 	KEY_UP   GLFW_KEY_UP
#define 	KEY_PAGE_UP   GLFW_KEY_PAGE_UP
#define 	KEY_PAGE_DOWN   GLFW_KEY_PAGE_DOWN
#define 	KEY_HOME   GLFW_KEY_HOME
#define 	KEY_END   GLFW_KEY_END
#define 	KEY_CAPS_LOCK   GLFW_KEY_CAPS_LOCK
#define 	KEY_SCROLL_LOCK   GLFW_KEY_SCROLL_LOCK
#define 	KEY_NUM_LOCK   GLFW_KEY_NUM_LOCK
#define 	KEY_PRINT_SCREEN   GLFW_KEY_PRINT_SCREEN
#define 	KEY_PAUSE   GLFW_KEY_PAUSE
#define 	KEY_F1   GLFW_KEY_F1
#define 	KEY_F2   GLFW_KEY_F2
#define 	KEY_F3   GLFW_KEY_F3
#define 	KEY_F4   GLFW_KEY_F4
#define 	KEY_F5   GLFW_KEY_F5
#define 	KEY_F6   GLFW_KEY_F6
#define 	KEY_F7   GLFW_KEY_F7
#define 	KEY_F8   GLFW_KEY_F8
#define 	KEY_F9   GLFW_KEY_F9
#define 	KEY_F10   GLFW_KEY_F10
#define 	KEY_F11   GLFW_KEY_F11
#define 	KEY_F12   GLFW_KEY_F12
#define 	KEY_F13   GLFW_KEY_F13
#define 	KEY_F14   GLFW_KEY_F14
#define 	KEY_F15   GLFW_KEY_F15
#define 	KEY_F16   GLFW_KEY_F16
#define 	KEY_F17   GLFW_KEY_F17
#define 	KEY_F18   GLFW_KEY_F18
#define 	KEY_F19   GLFW_KEY_F19
#define 	KEY_F20   GLFW_KEY_F20
#define 	KEY_F21   GLFW_KEY_F21
#define 	KEY_F22   GLFW_KEY_F22
#define 	KEY_F23   GLFW_KEY_F23
#define 	KEY_F24   GLFW_KEY_F24
#define 	KEY_F25   GLFW_KEY_F25
#define 	KEY_KP_0   GLFW_KEY_KP_0
#define 	KEY_KP_1   GLFW_KEY_KP_1
#define 	KEY_KP_2   GLFW_KEY_KP_2
#define 	KEY_KP_3   GLFW_KEY_KP_3
#define 	KEY_KP_4   GLFW_KEY_KP_4
#define 	KEY_KP_5   GLFW_KEY_KP_5
#define 	KEY_KP_6   GLFW_KEY_KP_6
#define 	KEY_KP_7   GLFW_KEY_KP_7
#define 	KEY_KP_8   GLFW_KEY_KP_8
#define 	KEY_KP_9   GLFW_KEY_KP_9
#define 	KEY_KP_DECIMAL   GLFW_KEY_KP_DECIMAL
#define 	KEY_KP_DIVIDE   GLFW_KEY_KP_DIVIDE
#define 	KEY_KP_MULTIPLY   GLFW_KEY_KP_MULTIPLY
#define 	KEY_KP_SUBTRACT   GLFW_KEY_KP_SUBTRACT
#define 	KEY_KP_ADD   GLFW_KEY_KP_ADD
#define 	KEY_KP_ENTER   GLFW_KEY_KP_ENTER
#define 	KEY_KP_EQUAL   GLFW_KEY_KP_EQUAL
#define 	KEY_LEFT_SHIFT   GLFW_KEY_LEFT_SHIFT
#define 	KEY_LEFT_CONTROL   GLFW_KEY_LEFT_CONTROL
#define 	KEY_LEFT_ALT   GLFW_KEY_LEFT_ALT
#define 	KEY_LEFT_SUPER   GLFW_KEY_LEFT_SUPER
#define 	KEY_RIGHT_SHIFT   GLFW_KEY_RIGHT_SHIFT
#define 	KEY_RIGHT_CONTROL   GLFW_KEY_RIGHT_CONTROL
#define 	KEY_RIGHT_ALT   GLFW_KEY_RIGHT_ALT
#define 	KEY_RIGHT_SUPER   GLFW_KEY_RIGHT_SUPER
#define 	KEY_MENU   GLFW_KEY_MENU
#define 	KEY_LAST   GLFW_KEY_MENU

// mouse
#define 	MOUSE_BUTTON_1   GLFW_MOUSE_BUTTON_1
#define 	MOUSE_BUTTON_2   GLFW_MOUSE_BUTTON_2
#define 	MOUSE_BUTTON_3   GLFW_MOUSE_BUTTON_3
#define 	MOUSE_BUTTON_4   GLFW_MOUSE_BUTTON_4
#define 	MOUSE_BUTTON_5   GLFW_MOUSE_BUTTON_5
#define 	MOUSE_BUTTON_6   GLFW_MOUSE_BUTTON_6
#define 	MOUSE_BUTTON_7   GLFW_MOUSE_BUTTON_7
#define 	MOUSE_BUTTON_8   GLFW_MOUSE_BUTTON_8
#define 	MOUSE_BUTTON_LAST   GLFW_MOUSE_BUTTON_8
#define 	MOUSE_BUTTON_LEFT   GLFW_MOUSE_BUTTON_1
#define 	MOUSE_BUTTON_RIGHT   GLFW_MOUSE_BUTTON_2
#define 	MOUSE_BUTTON_MIDDLE   GLFW_MOUSE_BUTTON_3


/// @brief The Input class handles Keyboard and Mouse.
class Input
{
public:
	Input(); ///< @brief Constructor of the Input
	virtual ~Input(); ///< @brief Destructor of the Input

	/// @brief updates the input from Keyboard and Mouse.
	/// @param[in] w GLFWwindow*
	void updateInput(GLFWwindow* w, Camera* c);

	// keys while down
	/// @brief Is this key pressed?
	/// @param key as int (see defines)
	/// @return bool key is pressed or not
	bool getKey(int key) { return _keys[key]; }
	/// @brief Is this key pressed?
	/// @param key as char (ie 'a')
	/// @return bool key is pressed or not
	bool getKey(char key) { return getKey((int) key); }
	/// @brief Is this mouse button pressed?
	/// @param button num
	/// @return bool button is pressed or not
	bool getMouse(int button) { return _mouse[button]; }

	// down
	/// @brief Is this key pressed? Only check first press down
	/// @param key as int (see defines)
	/// @return bool key is pressed first time or not
	bool getKeyDown(int key) { return _keysDown[key]; }
	/// @brief Is this key pressed? Only check first press down
	/// @param key as char (ie 'a')
	/// @return bool key is pressed first time or not
	bool getKeyDown(char key) { return getKeyDown((int) key); }
	/// @brief Is this mouse button pressed? Only check first press down
	/// @param button num
	/// @return bool button is pressed or not
	bool getMouseDown(int button) { return _mouseDown[button]; }

	// up
	/// @brief Is this key released?
	/// @param key as int (see defines)
	/// @return bool true or false
	bool getKeyUp(int key) { return _keysUp[key]; }
	/// @brief Is this key released?
	/// @param key as char (ie 'a')
	/// @return bool key is released or not
	bool getKeyUp(char key) { return getKeyUp((int) key); }
	/// @brief Is this mouse button released?
	/// @param button num
	/// @return bool button is released or not
	bool getMouseUp(int button) { return _mouseUp[button]; }

	// mouse
	/// @brief get X position of the Mouse
	/// @return _mouseX as double
	double getMouseX() { return _mouseX; }
	/// @brief get Y position of the Mouse
	/// @return _mouseY as double
	double getMouseY() { return _mouseY; }
	/// @brief get mouse pos
	glm::vec3 getCursor();
	/// @brief Set Mouse cursor to a certain position
	/// @param[in] x The X position
	/// @param[in] y The Y position
	/// @return void
	void setMouse(double x, double y) { glfwSetCursorPos(_window, x, y); };

	// window size
	/// @brief get width of the window
	/// @return _windowWidth as int
	int getWindowWidth() { return _windowWidth; }
	/// @brief get height of the window
	/// @return _windowHeight as int
	int getWindowHeight() { return _windowHeight; }

private:
	GLFWwindow* _window; ///< @brief GLFWwindow* _window
	void _handleKey(int key); ///< @brief update internal array of keys
	void _handleMouse(int key); ///< @brief update internal array of keys

	bool _keys[GLFW_KEY_LAST]; ///< @brief internal array of pressed keys
	bool _keysUp[GLFW_KEY_LAST]; ///< @brief internal array of released keys
	bool _keysDown[GLFW_KEY_LAST]; ///< @brief internal array of keys pressed the first time

	bool _mouse[GLFW_MOUSE_BUTTON_LAST]; ///< @brief internal array of pressed mouse buttons
	bool _mouseUp[GLFW_MOUSE_BUTTON_LAST]; ///< @brief internal array of released mouse buttons
	bool _mouseDown[GLFW_MOUSE_BUTTON_LAST]; ///< @brief internal array of mouse buttons pressed the first time

	double _mouseX; ///< @brief X position of the Mouse
	double _mouseY; ///< @brief Y position of the Mouse

	int _windowWidth; ///< @brief Width of the window
	int _windowHeight; ///< @brief Height of the window

	glm::vec3 cursor;
};

#endif /* INPUT_H */