#include "scene5.h"

Scene5::Scene5(){
	// set points at 0
	alive = false;
	active = false;
	rotateSpeed = 10;
	points = 0;
	barScale = 0;
	background = new Entity(SWIDTH/2, SHEIGHT/2);
	background->addSprite(ResourceManager::getSprite("assets/whoohh.tga"));
	background->scaleToSize(SWIDTH, SHEIGHT);

	this->addChild(background);

	// player stuff
	rotatePoint = new Entity();
	rotatePoint->layer = 5;
	circle = new Circle();
	circle->setPosition(0,100);
	// add child
	rotatePoint->addChild(circle);
	rotatePoint->layer = 4;
	this->addChild(rotatePoint);

	// goal stuff
	circlepoint = new Circlepoint();
	circlepoint->setPosition(SWIDTH/2,SHEIGHT/2);

	this->addChild(circlepoint);

	dis = new Vector2();

	bar = new Entity(SWIDTH/2, 0);
	bar->addSprite(new Sprite("assets/bar32.tga"));

	this->addChild(bar);

	bar->scaleToSize(SWIDTH, 25);

}

void Scene5::update(float deltaTime) {
	rotatePoint->position = Input::getCursor();
	if (active == false && alive == false) {
		if (Input::getKeyDown(KEY_SPACE)) {
			barScale = 0;
			active = true;
			alive = true;
			bar->scale = Vector2(1,1);
			bar->scaleToSize(SWIDTH, 25);
			circlepoint->setPosition(SWIDTH/2,SHEIGHT/2);
			rotatePoint->rotation = 0;
			circlepoint->active = true;
		}
	} else {
		// rotate the rotatePoint
		rotatePoint->rotation += rotateSpeed * deltaTime;

		dis->distance(circle->worldpos,circlepoint->worldpos);

		if (dis->magnitude() > circlepoint->getWidth()/2 - circle->getWidth()/2) {
			// he is out the circle
			if (barScale < -SWIDTH) {
				// player is dead
				circlepoint->active = false;
				active = false;
				alive = false;
				bar->scale = Vector2(0,0);
			} else {
				barScale -= 100 * deltaTime;
				bar->scaleToSize(SWIDTH + barScale, 25);
			}
		} else {
			// he is in the circle
			if (barScale < 0) {
				barScale += 50 * deltaTime;
				bar->scaleToSize(SWIDTH + barScale, 25);
			} else if (barScale > 0) {
				barScale = 0;
			}
		}

		// check if circlepoint position changed
		if (circlepoint->getChanged()) {
			// check distance
			dis->distance(circle->worldpos,circlepoint->oldPos);

			// check if player is in circle
			if (dis->magnitude() < (circlepoint->getWidth()/2 + circle->getWidth()/2) - 30) {
				circlepoint->addSpeed(0.05f);
				rotateSpeed++;
				points++;
			} else {
				barScale -= 180;
			}
			// reset circlepoint
			circlepoint->setChanged();
		}
	}
}

Scene5::~Scene5(){

}
