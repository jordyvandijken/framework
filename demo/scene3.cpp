#include "scene3.h"

Scene3::Scene3(){
  //test
  test = new Entity();
  test->addSprite(ResourceManager::getSprite("assets/brug.tga",128,128));
  // _test3
  _test3 = new Entity(100.0f, 100.0f);
  _test3->addSprite(ResourceManager::getSprite("assets/spritesheet.tga",128,128));
  // _test4
  _test4 = new Entity(50.0f, 50.0f);
  _test4->addSprite(ResourceManager::getSprite("assets/default.tga",128,128));
  _test4->scale = glm::vec2(0.5f,0.5f);
  // _test5
  _test5 = new Entity(-50.0f, -50.0f);
  _test5->addSprite(ResourceManager::getSprite("assets/brug.tga",128,128));
  _test5->scale = glm::vec2(0.5f,0.5f);

  // _test6
  _test6 = new Entity(-50.0f, 50.0f);
  _test6->addSprite(ResourceManager::getSprite("assets/spritesheet.tga",128,128));
  _test6->scale = glm::vec2(0.5f,0.5f);

  // _test7
  _test7 = new Entity(-50.0f, 50.0f);
  _test7->addSprite(ResourceManager::getSprite("assets/spritesheet.tga",128,128));
  _test7->scale = glm::vec2(0.5f,0.5f);

  test->addChild(_test3);
  _test3->rotation = 90.0;
  _test3->addChild(_test4);
  _test3->addChild(_test5);
  _test3->addChild(_test6);
  _test4->addChild(_test7);

  test->layer = 0;

  addEntity(test);

  std::cout << "scene3 is parent child test" << '\n';
}

void Scene3::update(float deltaTime){
  // speed
  float	speed = 300.0f; // 300 units / second

  // update entities
  test->position = Input::getCursor();
  _test3->rotation -= 40.0f * deltaTime;
  _test4->rotation = 360 - _test3->rotation;
  _test7->rotation = _test3->rotation;

  // rotate
  if (Input::getKey(KEY_A)){
    test->rotation += 1 * deltaTime * speed;
  }

  if (Input::getKey(KEY_D)){
    test->rotation -= 1 * deltaTime * speed;
  }

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

Scene3::~Scene3(){

}
