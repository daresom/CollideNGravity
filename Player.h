#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Object;

class Player
{
	public:
		sf::RectangleShape rect;
		float velocityX = 0, velocityY = 0;
		float x = 0, y = 0;
		bool isOnFloor = false;
		bool isKeyPressed = false;
		bool hasJumped = false;

		void setJumpForce(float num);
		float getJumpForce();

		void setMoveSpeed(float num);
		float getMoveSpeed();

		void setSprite(sf::Vector2f vect);
		void setSpritePos(float aX, float aY);
		sf::RectangleShape getSprite();

		sf::FloatRect getNextPos();

		void playerMovement(float dt, float gravity);
		void collision(Object object);
		void apply(float dt);

	private:
		float jumpForce = 600;
		float moveSpeed = 500;
		sf::FloatRect nextPos = rect.getGlobalBounds();

		
		
};

