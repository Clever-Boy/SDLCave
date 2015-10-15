#include "level.h"
#include "globals.h"

Level::Level()
{
}

Level::Level(std::string mapName, Vector2 spawnPoint, Graphics &graphics) :
	_mapName(mapName),
	_spawnPoint(spawnPoint),
	_size(Vector2(0,0))
{
	this->loadMap(mapName, graphics);
}

Level::~Level()
{
}

void Level::update(int elapsedTime)
{
}

void Level::draw(Graphics & graphics)
{
	//Draw the background
	SDL_Rect sourceRect = { 0,0,64,64 };
	SDL_Rect destRectangle;

	for (int x = 0; x < this->_size.x / 64; x++)
	{
		for (int y = 0; y < this->_size.y / 64; y++)
		{
			destRectangle.x = x * 64 * globals::SPRITE_SCALE;
			destRectangle.y = y * 64 * globals::SPRITE_SCALE;
			destRectangle.w = 64 * globals::SPRITE_SCALE;
			destRectangle.h = 64 * globals::SPRITE_SCALE;
			graphics.blitSurface(this->_backgroundTexture, &sourceRect, &destRectangle);
		}
	}
}

void Level::loadMap(std::string mapName, Graphics & graphics)
{
	// TEMPORARY CODE TO LOAD BACKGROUND
	this->_backgroundTexture = SDL_CreateTextureFromSurface(graphics.getRenderer(), graphics.loadImage("content/backgrounds/bkBlue.png"));
	this->_size = Vector2(1280,960);
}
