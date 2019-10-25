#include <iostream>
#include <SDL.h>
#include "Ball.cpp"
#include "Paddle.cpp"

int main(int, char**) {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	SDL_Window *win = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
	if (win == nullptr) {
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}

	SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == nullptr) {
		SDL_DestroyWindow(win);
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}

	Ball *b = new Ball(*ren, *win);
	Paddle *p = new Paddle(*ren, *win);
	SDL_Event e;

	//A sleepy rendering loop, wait for 3 seconds and render and present the screen each time
	while (true) {
		//First clear the renderer
		SDL_RenderClear(ren);
		
		SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
		b->render();
		b->move();

		while (SDL_PollEvent(&e) != 0)
		{
			p->handleEvent(e);
		}

		p->move();
		p->render();

		// check for collision
		SDL_Rect *ballPosition = b->getPosition();
		SDL_Rect *paddlePosition = p->getPosition();

		// the ball has either hit the paddle or passed the paddle
		if (ballPosition->x + ballPosition->w >= 640 - paddlePosition->w)
		{
			// did it hit the paddle?
			if (ballPosition->y + ballPosition->h >= paddlePosition->y && ballPosition->y <= paddlePosition->y + paddlePosition->h)
			{
				b->bounce();
			}
			else 
			{
				b->restart();
			}
		}

		SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
		//Update the screen
		SDL_RenderPresent(ren);
		//Take a quick break after all that hard work
	}

	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
	return 0;
}