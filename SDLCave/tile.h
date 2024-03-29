#ifndef TILE_H
#define TILE_H

#include <SDL.h>
#include "graphics.h"
#include "globals.h"

class Tile
{
public:
	Tile();
	Tile(SDL_Texture* tileset, Vector2 size, Vector2 tilesetPosition, Vector2 position);
	void update(float elapsedTime);
	void draw(Graphics &graphics);
private:
	SDL_Texture* _tileset;
	Vector2 _size;
	Vector2 _tilesetPosition;
	Vector2 _position;
};

#endif