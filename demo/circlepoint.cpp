#include "circlepoint.h"

Circlepoint::Circlepoint(){
    this->addSprite(ResourceManager::getSprite("assets/empty_circle.tga"));
    scale = Vector2(2,2);
    scaleSpeed = 0.2f;

    changed = false;

    active = false;

    oldPos = worldpos;
}

void Circlepoint::update(float deltaTime) {
    if (active) {
        scale.x -= scaleSpeed * deltaTime;
        scale.y -= scaleSpeed * deltaTime;

        if (scaleSpeed > 0.85) {
            scaleSpeed = 0.85;
        }

        if (scale.x <= 0.75f) {
            std::cout << "speed: " << scaleSpeed << '\n';
            changed = true;
            scale = Vector2(2,2);
            oldPos = worldpos;
            position = Vector2(rand() % 880 + 200, rand() % 380 + 200);
        }
    } else {
        scale = Vector2(2,2);
        scaleSpeed = 0.2f;

        changed = false;
    }
}

Circlepoint::~Circlepoint(){

}
