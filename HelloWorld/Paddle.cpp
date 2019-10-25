
#include <SDL.h>
#include <iostream>
class Paddle 
{

public:
	Paddle(SDL_Renderer& ren, SDL_Window& win)
	{
		rect = new SDL_Rect();
		rect->h = height;
		rect->w = width;
		renderer = &ren;
		SDL_GetWindowSize(&win, &windowWidth, &windowHeight);
		rect->x = windowWidth - width;
		rect->y = 0;
	}
	
	SDL_Rect* getPosition()
	{
		return rect;
	}

	void render()
	{
		SDL_RenderFillRect(renderer, rect);
	}

	void move()
	{
		if (rect->y <= 0)
		{
			rect->y = 0;
		}
		else if (rect->y >= windowHeight - height)
		{
			rect->y = windowHeight - height;
		}
	}

	void handleEvent(SDL_Event& e)
	{
		//If a key was pressed
		if (e.type == SDL_KEYDOWN)
		{
			//Adjust the velocity
			switch (e.key.keysym.sym)
			{
				case SDLK_UP:
				{
					rect->y -= vel;
					break;
				}
				case SDLK_DOWN: 
				{
					rect->y += vel; 
					break;
				}
			}
		}

	}

private:
	int width = 10;
	int height = 100;
	SDL_Renderer *renderer;
	SDL_Rect *rect;
	int windowWidth = 0;
	int windowHeight = 0;
	int vel = 25;
	int velY = 0;
};