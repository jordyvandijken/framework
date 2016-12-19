#include "entity.h"

int Entity::_nextNum = 0;

Entity::Entity(){
  _entityNum = _nextNum;
  _nextNum++;

  position = glm::vec2(0.0f,0.0f);
  scale = glm::vec2(1.0f,1.0f);
  rotation = 0.0f;

  layer = 0;

  parent = NULL;
  sprite = NULL;
}

void Entity::addSprite(Sprite* _sprite) {
  if (_sprite != NULL) {
    if (sprite != NULL) {
      sprite = _sprite;
    } else {
      delete sprite;
      sprite = _sprite;
    }
  }
}

void Entity::addChild(Entity* _child) {
  if(_child->parent != NULL) {
    _child->parent->removeChild(_child);
  }
  _child->parent = this;
  this->children.push_back(_child);
}

void Entity::removeChild(Entity* _child) {
  std::vector<Entity*>::iterator it = children.begin();
  while (it != children.end()) {
    if ((*it)->entityNum() == _child->entityNum()) {
      it = children.erase(it);
    } else {
      ++it;
    }
  }
}

Entity* Entity::getChild(int _num){
  return children[_num];
}

void Entity::setPosition(int _x, int _y) {
	this->position = glm::vec2(_x, _y);
}

void Entity::setPosition(glm::vec2 _pos){
	this->position = _pos;
}

Entity::~Entity(){
  if (sprite != NULL) {
    delete sprite;
  }
}
