#ifndef GAME_H
#define GAME_H

#include "graphics.h"
#include "animatedsprite.h"

class Game {
public:
	Game();
	~Game();

private:
	void gameLoop();
	void draw(Graphics &graphics);
	void update(float elapsedTime);

	AnimatedSprite _player;
};

#endif
