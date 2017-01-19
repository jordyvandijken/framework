/**
 * @file shader.h
 *
 * @brief The Shader header file.
 *
 * This file is part of a 2D OpenGL framework.
 *
 * - Copyright 2016 Jordy van Dijken <jordyvandijken@gmail.com>
 *   - Initial commit
 */

#ifndef SHADER_H
#define SHADER_H

/// @brief Load shader.
/// @param const char * vertex_file_path
/// @param const char * fragment_file_path
/// @return GLuint
GLuint loadShaders(const char * vertex_file_path, const char * fragment_file_path);

#endif /* SHADER_H */
