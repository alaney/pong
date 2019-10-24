#include "Ball.h"
#include <SDL.h>
#include <math.h>

class Ball
{
public:
	Ball(SDL_Renderer& ren, int width, int height)
	{
		rect = new SDL_Rect();
		rect->h = size;
		rect->w = size;
		renderer = &ren;
		windowHeight = height;
		windowWidth = width;
		rect->x = width / 2;
		rect->y = height / 2;
	}

	void move()
	{	
			rect->x += 10;
			rect->y += 10;
	}

	void render()
	{
		SDL_RenderFillRect(renderer, rect);
	}

private:
	int x = 100;
	int y = 100;
	int size = 20;
	SDL_Renderer *renderer;
	SDL_Rect *rect;
	int windowWidth = 0;
	int windowHeight = 0;
};
ELMOService1