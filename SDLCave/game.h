#ifndef GAME_H
#define GAME_H

#include "graphics.h"
#include "player.h"

class Game {
public:
	Game();
	~Game();

private:
	void gameLoop();
	void draw(Graphics &graphics);
	void update(float elapsedTime);

	Player _player;
};

#endif
