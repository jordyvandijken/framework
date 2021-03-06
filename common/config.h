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
#define SWIDTH      1280 ///< The screen width
#define SHEIGHT     720 ///< The screen height

#define FULLSCREEN  false ///< Fullscreen or not

#define WINDOWNAME              "Dickbutt for life <3" ///< The window name

#define SPRITEVERTEXSHADER      "shaders/sprite.vert" ///< vertexshader name
#define SPRITEFRAGMENTSHADER    "shaders/sprite.frag" ///< fragmentshader name

#define VSYNC       false ///< VSYNC on (1 - true) or off (0 - false)

#define RADTODEG    57.2957795 ///< radians to degrees
#define DEGTORAD    0.0174532925 ///< degrees to radians
#define PI			3.1415926535897932384626433832795 ///< @brief pi (180 deg) PI
#define HALF_PI		1.5707963267948966192313216916398 ///< @brief pi/2 (90 deg) HALF_PI
#define TWO_PI		6.283185307179586476925286766559  ///< @brief pi*2 (360 deg) TWO_PI

#define DEBUG       false ///< show some things for debuging

#define SHOWFPS     true ///< show fps in console

#define STANDARDSPRITEWIDTH     128  ///< in pixels
#define STANDARDSPRITEHEIGHT    128  ///< in pixels

#endif /* CONFIG_H */
