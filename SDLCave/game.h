#ifndef GAME_H
#define GAME_H

#include "graphics.h"

class Game {
public:
	Game();
	~Game();

private:
	void gameLoop();
	void draw(Graphics &graphics);
	void update(float elapsedTime);
};

#endif
