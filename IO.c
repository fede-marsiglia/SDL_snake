#include "IO.h"
#include "SDL2/SDL.h"
#include "snake.h"

bool 
snake_dir_change(SDL_Event *e)
{
	if(e->type == SDL_KEYDOWN) 
		switch(e->key.keysym.sym) {
		case UP:
			return true;
		case DOWN:
			return true;
		case LEFT:
			return true;
		case RIGHT:
			return true;
		}
	return false;
}	
