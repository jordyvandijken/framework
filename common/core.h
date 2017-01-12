/**
 * @file core.h
 *
 * @brief The Core header file.
 *
 * This file is part of a 2D OpenGL framework.
 *
 * - Copyright 2016 Jordy van Dijken <jordyvandijken@gmail.com>
 *   - Initial commit
 */

#ifndef CORE_H
#define CORE_H

#include <common/scene.h>
#include <common/renderer.h>
#include <vector>

/// @brief The Core class runs the Scenes.
class Core {
public:
	Core(); ///< @brief Constructor of the Camera
	virtual ~Core(); ///< @brief Destructor of the Camera
	/// @brief runs the scene that it gets.
	/// @param Scene* scene runs that scene
	/// @return void
	void runScene(Scene* _scene);
	/// @brief if you want to see your fps in the console.
	/// @param bool _c (true or false)
	/// @return void
	void setShowFps(bool _c);
	/// @brief tells the main program if it needs to stop.
	/// @return bool (true or false)
	bool mustQuit();

private:
	Renderer* renderer; ///< @brief Renderer instance of Core

	float deltaTime; ///< @brief float deltaTime

	bool needToShow; ///< @brief bool if it needs to show fps in console

	std::vector<int> averageFps; ///< @brief float deltaTime
	/// @brief calculate the deltaTime.
	/// @return void
	void calcDeltatime();
	/// @brief shows fps.
	/// @return void
	void showFps();
	/// @brief shows average fps at the end of program.
	/// @return void
	void showAverageFps();
};

#endif /* CORE_H */
