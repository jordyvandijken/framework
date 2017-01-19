#include "scene2.h"

Scene2::Scene2() {
  player = new Player();
  player->addSprite(ResourceManager::getSprite("assets/lel.tga", 128,128));
  player->setPosition(400,400);

  int intX = 80;
  int intY = 80;
  for (int q = 0; q < intX; q++) {
    for (int w = 0; w < intY; w++) {
      Entity* t = new Entity(128 * q, 128 * w);
      if (q == 0 || q == intX - 1 || w == 0 || w == intY - 1) {
        t->addSprite(ResourceManager::getSprite("assets/doge.tga", 128,128));
      } else {
        t->addSprite(ResourceManager::getSprite("assets/default.tga", 128,128));
      }
      addEntity(t);
    }
  }

  std::cout << "scene2 is " << intX << " x " << intY << " tiles | total of: " << intX * intY << '\n';
  addEntity(player);
}

void Scene2::update(float deltaTime) {
  if (Input::getKey(KEY_UP)) {
    player->updatePos(glm::vec2(0,-300 * deltaTime));
  }
  if (Input::getKey(KEY_DOWN)) {
    player->updatePos(glm::vec2(0,300 * deltaTime));
  }
  if (Input::getKey(KEY_LEFT)) {
    player->updatePos(glm::vec2(-300 * deltaTime,0));
  }
  if (Input::getKey(KEY_RIGHT)) {
    player->updatePos(glm::vec2(300 * deltaTime,0));
  }
  camera->setPosition(glm::vec2(player->position.x - SWIDTH/2, player->position.y - SHEIGHT/2));
}

Scene2::~Scene2() {

}
