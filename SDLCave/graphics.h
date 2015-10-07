#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <SDL.h>
#include <map>
#include <string>

class Graphics {
public:
	Graphics();
	~Graphics();

	/* SDL_Surface* loadImage
	Load an image to the _spriteSheets map if it not already exists
	It avoid the load a single Image multiple times
	Return the image whether if it just loaded it or it was already loaded
	*/
	SDL_Surface* loadImage(const std::string &FilePath);

	/* void blitSurface
	* Render a texture to a certain part of the screen
	*/
	void blitSurface(SDL_Texture* source, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle);
	
	/* void flip
	* Render everything to the screen
	*/
	void flip();

	/* void clear
	* Clear the entire screen
	*/
	void clear();

	SDL_Renderer* getRenderer() const;
private:
	SDL_Window* _window;
	SDL_Renderer* _renderer;
	std::map<std::string, SDL_Surface*> _spriteSheets;
};

#endif 