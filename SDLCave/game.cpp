#include "SDL.h"
#include <SDL_image.h>

#include "input.h"
#include "game.h"
#include "player.h"
#include "graphics.h"


/* Class : Game
Holds the information for the game loop
*/

namespace {
	const int FPS = 50;
	const int MAX_FRAME_TIME = 5 * 1000 / FPS;
}

Game::Game()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	this->gameLoop();
}

Game::~Game()
{
	
}

void Game::gameLoop()
{
	Graphics graphics;
	Input input;
	SDL_Event event;

	this->_player = Player(graphics,100,100);
	this->_level = Level("map1", Vector2(0, 0), graphics);

	int LAST_UPDATE_TIME = SDL_GetTicks();

	while (true) {
		input.beginNewFrame();

		if (SDL_PollEvent(&event)) {
			if (event.type == SDL_KEYDOWN)
			{
				if (event.key.repeat == 0)
				{
					input.KeyDownEvent(event);
				}
			}

			else if (event.type == SDL_KEYUP)
			{
				input.KeyUpEvent(event);
			}
			
			else if (event.type == SDL_QUIT)
			{
				return;
			}
		}

		if (input.wasKeyPressed(SDL_SCANCODE_ESCAPE))
		{
			return;
		}
		else if (input.isKeyHeld(SDL_SCANCODE_LEFT) == true)
		{
			_player.moveLeft();
		}
		else if (input.isKeyHeld(SDL_SCANCODE_RIGHT) == true)
		{
			_player.moveRight();
		}

		if (!input.isKeyHeld(SDL_SCANCODE_RIGHT) && !input.isKeyHeld(SDL_SCANCODE_LEFT))
		{
			_player.stopMoving();
		}

		const int CURRENT_TIME_MS = SDL_GetTicks();
		int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;
		this->update(std::fmin(ELAPSED_TIME_MS, MAX_FRAME_TIME));
		LAST_UPDATE_TIME = CURRENT_TIME_MS;

		this->draw(graphics);
	}
}

void Game::draw(Graphics &graphics)
{
	graphics.clear();

	this->_level.draw(graphics);
	this->_player.draw(graphics);	

	graphics.flip();
}

void Game::update(float elapsedTime)
{
	this->_level.update(elapsedTime);
	this->_player.update(elapsedTime);
	
}
