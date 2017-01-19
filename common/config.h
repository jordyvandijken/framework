/**
 * @file config.h
 *
 * @brief The Config header file.
 *
 * This file is part of a 2D OpenGL framework.
 *
 * - Copyright 2016 Jordy van Dijken <jordyvandijken@gmail.com>
 *   - Initial commit
 */

#ifndef CONFIG_H
#define CONFIG_H

// screen width and height
#define SWIDTH 1280 ///< The screen width
#define SHEIGHT 720 ///< The screen height

#define FULLSCREEN false ///< Fullscreen or not

#define WINDOWNAME "Dickbutt for life <3" ///< The window name

#define SPRITEVERTEXSHADER "shaders/sprite.vert" ///< vertexshader name
#define SPRITEFRAGMENTSHADER "shaders/sprite.frag" ///< fragmentshader name

#define VSYNC false ///< VSYNC on (1 - true) or off (0 - false)

#define RADTODEG 57.2957795 ///< radians to degrees
#define DEGTORAD 0.0174532925 ///< degrees to radians

#define DEBUG false ///< show some things for debuging

#define SHOWFPS true ///< show fps in console

#endif /* CONFIG_H */
