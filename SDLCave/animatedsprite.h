#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H

#include <map>
#include <string>
#include <vector>

#include "sprite.h"
#include "globals.h"

class Graphics;

/* Class : AnimatedSprite
Holds the informations of the animated sprites
*/

class AnimatedSprite : public Sprite {
public:
	AnimatedSprite();
	AnimatedSprite(Graphics &graphics, const std::string &filePath, int sourceX, int sourceY, int width, int height, float posX, float posY, float timeToUpdate);
	
	/* void playAnimation
	Plays the animation provided in parameter if it's not already playing
	*/
	void playAnimation(std::string animation, bool once = false);

	/* void update
	Update the animated sprite (timer)
	*/
	void update(int elapsedTime);

	/* void draw
	Draw the sprite on the screen
	*/
	void draw(Graphics &graphics, int x, int y);

	/* void setupAnimations
	A required function to setup all the animations for the animated sprite
	*/
	virtual void setupAnimations();

protected:
	double _timeToUpdate;
	bool _currentAnimationOnce;
	std::string _currentAnimation;

	/* void addAnimation
	Add an animation to the map of animations
	*/
	void addAnimation(int frames,int x, int y, std::string name, int width, int height, Vector2 offset);

	/* void resetAnimations
	Reset all the animations of this sprite
	*/
	void resetAnimations();

	/* void stopAnimation
	Stop the current animation
	*/
	void stopAnimation();

	/* void setVisible
	Change the visibility of the sprite
	*/
	void setVisible(bool visible);

	/* void animationDone
	The logic that happened when an animation ends.
	*/
	virtual void animationDone(std::string currentAnimation);

private:
	std::map<std::string, std::vector<SDL_Rect>> _animations;
	std::map<std::string, Vector2> _offsets;

	int _frameIndex;
	float _timeElapsed;
	bool _visible;

};

#endif
