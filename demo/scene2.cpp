#include "scene2.h"

Scene2::Scene2() {
  player = new Player();
  player->addSprite(new Sprite("assets/default.tga",128,128));
  player->setPosition(400,400);

  addEntity(player);
}

void Scene2::update(float deltaTime) {
  if (input->getKey(KEY_UP)) {
    player->updatePos(glm::vec2(0,-300 * deltaTime));
  }
  if (input->getKey(KEY_DOWN)) {
    player->updatePos(glm::vec2(0,300 * deltaTime));
  }
  if (input->getKey(KEY_LEFT)) {
    player->updatePos(glm::vec2(-300 * deltaTime,0));
  }
  if (input->getKey(KEY_RIGHT)) {
    player->updatePos(glm::vec2(300 * deltaTime,0));
  }
}

Scene2::~Scene2() {
  for(int i = 0; i < entities.size(); i++) {
    Entity* p = entities[i];
    delete p;
    entities.erase (entities.begin() + i);
  }
  if (entities.size() > 1) {
    Entity* p = entities[0];
    delete p;
    entities.erase (entities.begin());
  }
}
