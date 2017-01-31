#include "scene2.h"

Scene2::Scene2() {
  player = new Player();
  player->addSprite(ResourceManager::getSprite("assets/doge.tga"));
  player->setPosition(400,400);
  player->scaleToSize(128,128);

  int intX = 300;
  int intY = 300;
  for (int q = 0; q < intX; q++) {
    for (int w = 0; w < intY; w++) {
      Entity* t = new Entity(128 * q, 128 * w);
      if (q == 0 || q == intX - 1 || w == 0 || w == intY - 1) {
        t->addSprite(ResourceManager::getSprite("assets/doge.tga"));
      } else {
        t->addSprite(ResourceManager::getSprite("assets/default.tga"));
      }
      t->scaleToSize(128,128);
      addChild(t);
    }
  }

  std::cout << "scene2 is " << intX << " x " << intY << " tiles | total of: " << intX * intY << '\n';
  addChild(player);
}

void Scene2::update(float deltaTime) {
  if (Input::getKey(KEY_UP)) {
    player->updatePos(Vector2(0.0f,-300.0f * deltaTime));
  }
  if (Input::getKey(KEY_DOWN)) {
    player->updatePos(Vector2(0.0f,300.0f * deltaTime));
  }
  if (Input::getKey(KEY_LEFT)) {
    player->updatePos(Vector2(-300.0f * deltaTime,0.0f));
  }
  if (Input::getKey(KEY_RIGHT)) {
    player->updatePos(Vector2(300.0f * deltaTime,0.0f));
  }
  camera->setPosition(glm::vec2(player->position.x - SWIDTH/2, player->position.y - SHEIGHT/2));
}

Scene2::~Scene2() {

}
