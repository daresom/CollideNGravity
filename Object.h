#pragma once
#include "Player.h"
#include <SFML/Graphics.hpp>

class Player;

class Object
{
	public:
		void setSpriteSize(sf::Vector2f vector);
		sf::RectangleShape getSprite();

		void setCords(float setX, float setY);

	private:
		sf::RectangleShape sprite;
		float x = 0, y = 0;
};

