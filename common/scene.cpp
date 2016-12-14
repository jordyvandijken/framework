#include "scene.h"

Scene::Scene(){
  _camera = new Camera();

}

void Scene::addEntity(Entity* _entity) {
  entities.push_back(_entity);
}

Scene::~Scene(){
  delete _camera;
}
