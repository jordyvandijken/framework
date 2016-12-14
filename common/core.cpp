#include "core.h"

Core::Core(){
 renderer = new Renderer();
 deltaTime = 0;
 needToShow = false;
}

void Core::runScene(Scene* _scene) {
  calcDeltatime();
  if (needToShow) {
    showFps();
  }
  renderer->run(_scene, deltaTime);
}

void Core::calcDeltatime() {
  // glfwGetTime is called only once, the first time this function is called
  static double lastTime = glfwGetTime();

  // Compute time difference between current and last frame
  double currentTime = glfwGetTime();
  deltaTime = float(currentTime - lastTime);
  // For the next frame, the "last time" will be "now"
  lastTime = currentTime;
}

void Core::showFps() {
  static int fps = 0;
  static float del_time = 0;
  if (del_time >= 1) {
    std::cout << "FPS: " << fps << '\n';
    fps = 0;
    del_time = 0;
  }
  fps++;
  del_time += deltaTime;
}

bool Core::mustQuit() {
  return renderer->mustQuit();
}

void Core::setShowFps(bool _c){
  needToShow = _c;
}

Core::~Core(){
  delete renderer;
}
