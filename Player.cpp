#include "Player.h"
#include "Object.h"

// Getter and Setter methods
void Player::setJumpForce(float num) {
	Player::jumpForce = num;
}

float Player::getJumpForce() {
	return Player::jumpForce;
 }

void Player::setMoveSpeed(float num) {
	Player::moveSpeed = num;
}

float Player::getMoveSpeed() {
	return Player::moveSpeed;
}

void Player::setSprite(sf::Vector2f vect) {
	Player::rect.setFillColor(sf::Color::Red);
	Player::rect.setSize(vect);
}

void Player::setSpritePos(float aX, float aY) {
	Player::x = aX;
	Player::y = aY;
	Player::rect.setPosition(Player::x, Player::y);
}

sf::RectangleShape Player::getSprite() {
	return Player::rect;
}

sf::FloatRect Player::getNextPos() {
	return Player::nextPos;
}

//Movement

void Player::apply(float dt) {
	if (!Player::isOnFloor) { //Gravity
		Player::velocityY += 2000 * dt;
	}

	Player::nextPos = Player::rect.getGlobalBounds();
	Player::nextPos.left += velocityX;
	Player::nextPos.top += velocityY;

	Player::x += Player::velocityX;
	Player::y += Player::velocityY * dt;

	Player::rect.setPosition(Player::x, Player::y);

	Player::velocityX = 0;
}


void Player::playerMovement(float dt, float gravity) {
	Player::nextPos = Player::rect.getGlobalBounds();
	Player::isKeyPressed = false;
	//Movement
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		Player::velocityX = -Player::moveSpeed * dt;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		Player::velocityX = Player::moveSpeed * dt;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) { //Jump
		Player::isKeyPressed = true;
	}
	
	if (Player::isOnFloor) {
		Player::hasJumped = false;
	}

	if (Player::isKeyPressed && Player::isOnFloor && !Player::hasJumped) {
		Player::velocityY = 0;
		Player::velocityY = -jumpForce;
		Player::isOnFloor = false;
		Player::hasJumped = true;
	}
} 
