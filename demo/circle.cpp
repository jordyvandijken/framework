#include "circle.h"

Circle::Circle(){
    this->addSprite(ResourceManager::getSprite("assets/circle.tga"));
    this->scale = Vector2(0.5,0.5);
}

void Circle::update(float deltaTime) {

}

Circle::~Circle(){

}
