#ifndef PLAYER_H
#define PLAYER_H

#include "animatedsprite.h"
#include "globals.h"

class Player : public AnimatedSprite
{
public:
	Player();
	Player(Graphics &graphics, float x, float y);
	void draw(Graphics &graphics);
	void update(float elapsedTime);

	/* void moveLeft
	Move the player to the left by _dx
	*/
	void moveLeft();

	/* void moveRight
	Move the player to the right by _dx
	*/
	void moveRight();

	/*void stopMoving
	Make the player stop moving
	*/
	void stopMoving();
	
	virtual void animationDone(std::string currentAnimation);
	virtual void setupAnimations();

private:
	float _dx, _dy;

	Direction _facing;
};

#endif
