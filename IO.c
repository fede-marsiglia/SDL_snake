#include "IO.h"
#include "SDL2/SDL.h"
#include "snake.h"

bool 
snake_dir_change(SDL_Event *e)
{
	if(e->type == SDL_KEYDOWN) 
		switch(e->key.keysym.sym) {

		case UP: case DOWN: case LEFT: case RIGHT:
			return true;
		default:
			return false;
		}

	return false;
}	
