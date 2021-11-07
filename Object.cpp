#include "Object.h"

void Object::setSpriteSize(sf::Vector2f vector) {
	Object::sprite.setSize(vector);
}

sf::RectangleShape Object::getSprite() {
	return Object::sprite;
}

void Object::setCords(float setX, float setY) {
	Object::x = setX;
	Object::y = setY;

	Object::sprite.setPosition(Object::x, Object::y);
}
