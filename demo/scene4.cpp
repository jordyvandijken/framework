#include "scene4.h"

Scene4::Scene4(){
  //test
  Entity* stand = new Entity(SWIDTH/2,SHEIGHT/2);
  stand->addSprite(ResourceManager::getSprite("assets/doge.tga",128,128));
  addEntity(stand);

  entitiesList.push_back(stand);
  int amount = 100;
  for (int i = 0; i < amount; i++) {
    //test
    Entity* test = new Entity(151, 151);
    test->addSprite(ResourceManager::getSprite("assets/doge.tga",128,128));
    test->scale *= 0.89404;
    entitiesList[i]->addChild(test);
    entitiesList.push_back(test);
  }

  std::cout << "scene4 is parent child test" << '\n';
}

void Scene4::update(float deltaTime){
  for (int q = 0; q < entitiesList.size(); q++) {
    entitiesList[q]->rotation += 30 * deltaTime;
  }

  camera->setPosition (glm::vec2(entitiesList[entitiesList.size()-1]->getWorldPosition().x - SWIDTH/2, entitiesList[entitiesList.size()-1]->getWorldPosition().y - SHEIGHT/2));
}

Scene4::~Scene4(){

}
