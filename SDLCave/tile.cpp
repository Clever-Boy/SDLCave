#include "tile.h"
#include "graphics.h"

#include <SDL.h>

Tile::Tile()
{
}

Tile::Tile(SDL_Texture * tileset, Vector2 size, Vector2 tilesetPosition, Vector2 position) :
	_tileset(tileset),
	_size(size),
	_tilesetPosition(tilesetPosition),
	_position(Vector2(position.x * globals::SPRITE_SCALE, position.y*globals::SPRITE_SCALE))
{
}

void Tile::draw(Graphics & graphics)
{
	SDL_Rect sourceRect = { this->_tilesetPosition.x, this->_tilesetPosition.y,this->_size.x,this->_size.y };
	SDL_Rect destinationRect = { this->_position.x, this->_position.y,this->_size.x * globals::SPRITE_SCALE,this->_size.y * globals::SPRITE_SCALE };

	graphics.blitSurface(this->_tileset, &sourceRect, &destinationRect);
}
