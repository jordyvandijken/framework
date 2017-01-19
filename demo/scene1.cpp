#include "scene1.h"

Scene1::Scene1(){
  flip = false;
  _flip = false;
  //test
  test = new Entity();
  test->addSprite(ResourceManager::getSprite("assets/default.tga",128,128));
  // _test
  Entity* _test = new Entity();
  _test->position = glm::vec2(100.0f, 100.0f);
  _test->addSprite(ResourceManager::getSprite("assets/pencils.tga",128,128));
  // _test2
  Entity* _test2 = new Entity();
  _test2->position = glm::vec2(300.0f, 300.0f);
  _test2->addSprite(ResourceManager::getSprite("assets/pencils.tga",128,128));
  // _test3
  Entity* _test3 = new Entity();
  _test3->position = glm::vec2(100.0f, 100.0f);
  _test3->addSprite(ResourceManager::getSprite("assets/spritesheet.tga",128,128));
  // _test4
  Entity* _test4 = new Entity();
  _test4->position = glm::vec2(50.0f, 50.0f);
  _test4->addSprite(ResourceManager::getSprite("assets/default.tga",128,128));
  _test4->scale = glm::vec2(0.5f,0.5f);
  // _test5
  Entity* _test5 = new Entity();
  _test5->position = glm::vec2(-50.0f, -50.0f);
  _test5->addSprite(ResourceManager::getSprite("assets/default.tga",128,128));
  _test5->scale = glm::vec2(0.5f,0.5f);

  test->addChild(_test3);
  _test3->rotation = 90.0;
  _test3->addChild(_test4);
  _test3->addChild(_test5);

  _test->layer = 2;
  test->layer = 1;


  addEntity(test);
  addEntity(_test);
  addEntity(_test2);

  std::cout << "scene1 is a simple scene" << '\n';
}

void Scene1::update(float deltaTime){
  float	speed = 300.0f; // 300 units / second

  test->position = Input::getCursor();

  // Move up
  if (Input::getKey(KEY_UP)){
    camera->addPosition(glm::vec2(0,-1) * deltaTime *  speed);
  }
  // Move down
  if (Input::getKey(KEY_DOWN)){
    camera->addPosition(glm::vec2(0,1) * deltaTime *  speed);
  }
  // Strafe right
  if (Input::getKey(KEY_RIGHT)){
    camera->addPosition(glm::vec2(1,0) * deltaTime *  speed);
  }
  // Strafe left
  if (Input::getKey(KEY_LEFT)){
    camera->addPosition(glm::vec2(-1,0) * deltaTime *  speed);
  }
}

Scene1::~Scene1(){

}
