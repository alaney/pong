#include "Ball.h"
#include <SDL.h>
#include <math.h>

class Ball
{
public:
	Ball(SDL_Renderer& ren, SDL_Window& win)
	{
		rect = new SDL_Rect();
		rect->h = size;
		rect->w = size;
		renderer = &ren;
		SDL_GetWindowSize(&win, &windowWidth, &windowHeight);
		rect->x = windowWidth / 2;
		rect->y = windowHeight / 2;
	}

	void move()
	{
		if (rect->x >= windowWidth - size)
		{
			xModifier = -vel;
		}
		else if (rect->x <= 0)
		{
			xModifier = vel;
		}

		if (rect->y >= windowHeight - size)
		{
			yModifier = -vel;
		}
		else if (rect->y <= 0)
		{
			yModifier = vel;
		}

		rect->x += xModifier;
		rect->y += yModifier;
	}

	void render()
	{
		SDL_RenderFillRect(renderer, rect);
	}

private:
	int x = 100;
	int y = 100;
	int vel = 10;
	int size = 20;
	SDL_Renderer *renderer;
	SDL_Rect *rect;
	int windowWidth = 0;
	int windowHeight = 0;
	int yModifier = vel;
	int xModifier = vel;
};
