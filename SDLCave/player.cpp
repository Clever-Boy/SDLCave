#include "player.h"
#include "graphics.h"

namespace player_constants
{
	const float WALK_SPEED = 0.2;
}

Player::Player()
{
}

Player::Player(Graphics &graphics, float x, float y) : AnimatedSprite(graphics, "content/sprites/MyChar.png", 0, 0, 16, 16, x, y, 100)
{
	graphics.loadImage("content/sprites/MyChar.png");
	this->setupAnimations();
	this->playAnimation("IdleLeft");
}

void Player::setupAnimations()
{
	this->addAnimation(3, 0, 0, "runLeft", 16, 16, Vector2(0, 0));
	this->addAnimation(3, 0, 16, "runRight", 16, 16, Vector2(0, 0));
	this->addAnimation(1, 0, 0, "idleLeft", 16, 16, Vector2(0, 0));
	this->addAnimation(1, 0, 16, "idleRight", 16, 16, Vector2(0, 0));
}

void Player::animationDone(std::string currentAnimation)
{
}

void Player::moveLeft()
{
	this->_dx = -player_constants::WALK_SPEED;
	this->playAnimation("runLeft");
	this->_facing = LEFT;
}

void Player::moveRight()
{
	this->_dx = player_constants::WALK_SPEED;
	this->playAnimation("runRight");
	this->_facing = RIGHT;
}

void Player::stopMoving()
{
	this->_dx = 0;
	this->playAnimation(this->_facing == LEFT ? "idleLeft" : "idleRight");
}

void Player::draw(Graphics &graphics)
{
	AnimatedSprite::draw(graphics, this->_x, this->_y);
}

void Player::update(float elapsedTime)
{
	//move by _dx
	this->_x += this->_dx * elapsedTime;
	
	AnimatedSprite::update(elapsedTime);
}