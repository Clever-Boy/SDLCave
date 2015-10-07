#include "graphics.h"
#include "globals.h"
#include <SDL.h>
#include <SDL_image.h>

/* Class : Graphics
Contains all the informations related to the graphics of the game
*/

Graphics::Graphics()
{
	SDL_CreateWindowAndRenderer(globals::SCREEN_WIDTH,globals::SCREEN_HEIGHT, 0, &this->_window, &this->_renderer);
	SDL_SetWindowTitle(this->_window, "SDLCave");
}

Graphics::~Graphics()
{
	SDL_DestroyWindow(this->_window);
}

SDL_Renderer * Graphics::getRenderer() const
{
	return this->_renderer;
}

SDL_Surface* Graphics::loadImage(const std::string &FilePath)
{
	if (this->_spriteSheets.count(FilePath) == 0)
	{
		this->_spriteSheets[FilePath] = IMG_Load(FilePath.c_str());
	}

	return this->_spriteSheets[FilePath];
}

void Graphics::blitSurface(SDL_Texture* source, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle)
{
	SDL_RenderCopy(this->_renderer, source, sourceRectangle, destinationRectangle);
}

void Graphics::flip()
{
	SDL_RenderPresent(this->_renderer);
}

void Graphics::clear()
{
	SDL_RenderClear(this->_renderer);
}
