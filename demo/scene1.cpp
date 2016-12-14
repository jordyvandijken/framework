#include "scene1.h"

Scene1::Scene1(){
  flip = false;
  _flip = false;
  //test
  test = new Entity();
  test->addSprite(new Sprite("assets/pencils.tga",128,128));
  // _test
  Entity* _test = new Entity();
  _test->position = glm::vec2(100.0f, 100.0f);
  _test->addSprite(new Sprite("assets/pencils.tga",128,128));
  // _test2
  Entity* _test2 = new Entity();
  _test2->position = glm::vec2(300.0f, 300.0f);
  _test2->addSprite(new Sprite("assets/pencils.tga",128,128));
  // _test3
  Entity* _test3 = new Entity();
  _test3->position = glm::vec2(100.0f, 100.0f);
  _test3->addSprite(new Sprite("assets/pencils.tga",128,128));
  // _test4
  Entity* _test4 = new Entity();
  _test4->position = glm::vec2(50.0f, 50.0f);
  _test4->addSprite(new Sprite("assets/pencils.tga",128,128));
  _test4->scale = glm::vec2(0.5f,0.5f);

  test->addChild(_test3);
  _test3->rotation = 90.0;
  _test3->addChild(_test4);

  test->layer = 1;

  addEntity(test);
  addEntity(_test);
  addEntity(_test2);
}

void Scene1::update(float deltaTime){


  // update entities
  entities[0]->position = glm::vec2(camera()->getCursor().x,_camera->getCursor().y);
  entities[1]->rotation += 40.0f * deltaTime;
  entities[0]->getChild(0)->rotation -= 40.0f * deltaTime;
  entities[0]->getChild(0)->getChild(0)->rotation = 360 - entities[0]->getChild(0)->rotation;


  if (entities[2]->scale.x < 2 && flip == false) {
    entities[2]->scale += glm::vec2(1.0f,1.0f) * deltaTime;
  } else {
      flip = true;
  }
  if (entities[2]->scale.x > 0 && flip == true){
    entities[2]->scale += glm::vec2(-1.0f,-1.0f) * deltaTime;
  } else {
    flip = false;
  }

  if (entities[0]->scale.x < 1.5f && _flip == false) {
    entities[0]->scale += glm::vec2(1.0f,1.0f) * deltaTime;
  } else {
      _flip = true;
  }
  if (entities[0]->scale.x > 0.5f && _flip == true){
    entities[0]->scale += glm::vec2(-1.0f,-1.0f) * deltaTime;
  } else {
    _flip = false;
  }

  // // Right and Down vector
  // glm::vec3 right = glm::vec3(1, 0, 0);
  // glm::vec3 up = glm::vec3(0, -1, 0);
  //
  // float	speed = 300.0f; // 300 units / second
  //
  // // Move up
  // if (glfwGetKey( window, GLFW_KEY_UP ) == GLFW_PRESS){
  //   camera()->setPosition(up * deltaTime *  speed);
  // }
  // // Move down
  // if (glfwGetKey( window, GLFW_KEY_DOWN ) == GLFW_PRESS){
  //   camera()->setPosition(-up * deltaTime *  speed);
  // }
  // // Strafe right
  // if (glfwGetKey( window, GLFW_KEY_RIGHT ) == GLFW_PRESS){
  //   camera()->setPosition(right * deltaTime *  speed);
  // }
  // // Strafe left
  // if (glfwGetKey( window, GLFW_KEY_LEFT ) == GLFW_PRESS){
  //   camera()->setPosition(-right * deltaTime *  speed);
  // }
}

Scene1::~Scene1(){
  for(int i = 0; i <= entities.size(); i++) {
    Entity* p = entities[i];
    delete p;
    entities.erase (entities.begin() + i);
  }
  Entity* p = entities[0];
  delete p;
  entities.erase (entities.begin());
}
