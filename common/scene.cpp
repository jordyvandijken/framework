#include "scene.h"

Scene::Scene(){
  srand (time(NULL));

  camera = new Camera();
  input = new Input();
}

void Scene::addEntity(Entity* _entity) {
  entities.push_back(_entity);
}

Scene::~Scene(){
  delete camera;
  delete input;

  if (entities.size() > 1) {
    for(int i = 0; i <= entities.size(); i++) {
      Entity* p = entities[i];
      delete p;
      entities.erase (entities.begin() + i);
    }
  }
  if (entities.size() == 1) {
    Entity* p = entities[0];
    delete p;
    entities.erase (entities.begin());
  }
}
