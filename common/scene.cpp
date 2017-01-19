#include "scene.h"

Scene::Scene(){
  srand (time(NULL));

  camera = new Camera();
}

void Scene::addEntity(Entity* _entity) {
  entities.push_back(_entity);
}

Scene::~Scene(){
  if (camera) {
    delete camera;
  }

  std::vector<Entity*>::iterator it = entities.begin();
	while (it != entities.end()) {
		delete (*it);
		it = entities.erase(it);
	}
}
