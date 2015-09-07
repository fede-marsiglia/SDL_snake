#ifndef GAME
#define GAME

#include "snake.h"
#include "food.h"
#include "SDL2/SDL.h"

#define DEF_WIN_WIDTH	640
#define DEF_WIN_HEIGHT	480

struct game {
	struct snake 	snake;
	SDL_Rect	food;
	SDL_Window 	*win;
	SDL_Renderer 	*rend;	
	SDL_Event 	event;
};

struct game
game(void);

void
game_start(struct game*);

void
free_resources(struct game*);

#endif

