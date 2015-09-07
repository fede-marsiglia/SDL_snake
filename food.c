#include <stdlib.h>
#include "game.h"
#include "food.h"

SDL_Rect
food(void)
{
	SDL_Rect food;

	food.x = 0;
	food.y = 0;
	food.w = 10;
	food.h = 10;

	return food;
}

void 
move_food(SDL_Rect *f) 
{
	f->x = rand() % DEF_WIN_WIDTH;
	f->y = rand() % DEF_WIN_HEIGHT;
}
