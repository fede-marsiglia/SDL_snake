#include <stdlib.h> 
#include "snake.h"
#include "food.h"
#include "SDL2/SDL.h"
#include "game.h"

struct snake
snake(void) 
{
	struct snake s;

	s.len = SNAKE_INIT_LEN; 
	s.max_len = SNAKE_INIT_MAX_LEN; 
	s.buff.st = EMPTY;
	s.dir = RIGHT;
	s.head = (SDL_Rect*)malloc(sizeof(SDL_Rect) * s.max_len);
	s.head->x = 0;
	s.head->y = 0;
	s.head->w = SNAKE_BLOCK_LEN;
	s.head->h = SNAKE_BLOCK_LEN;

	return s;
}

#define DOUBLE(x) (x) *= 2

void
extend(struct snake *s) 
{
	DOUBLE(s->max_len);
	s->head = realloc(s->head, sizeof(SDL_Rect) * s->max_len);
}

void
move_snake(struct snake *s)
{
	SDL_Rect *last;
	last = s->head + s->len - 1;
	
	for(; last != s->head; last--)
		*last = *(last-1);

	switch(s->dir) {
		case UP:
			(s->head->y) -= SNAKE_BLOCK_LEN;
			break;
		case DOWN:
			(s->head->y) += SNAKE_BLOCK_LEN;
			break;
		case LEFT:
			(s->head->x) -= SNAKE_BLOCK_LEN;
			break;
		case RIGHT:
			(s->head->x) += SNAKE_BLOCK_LEN;
			break;
	}
}

bool 
full(struct snake *s)
{
	return s->len == s->max_len;
}

void
add_block(struct snake *s)
{
	if(full(s)) 
		extend(s);

	SDL_Rect *tail;
	tail = s->head + s->len;
        *tail = s->buff.block;
	s->buff.st = EMPTY;
	s->len++; 
}

void
queue_block(struct snake *s) 
{
	SDL_Rect *tail;
	tail = s->head + s->len - 1;
	s->buff.block = *tail;
	s->buff.st = FULL;
}

bool
eat_himself(struct snake *s) 
{
	int i;
	for(i = 1; i < s->len; i++) 
		if(SDL_HasIntersection(s->head, s->head+i))
				return true; 
	return false; 
}

SDL_bool 
eat_food(struct snake *s, 
	 SDL_Rect *f)
{
	return SDL_HasIntersection(s->head, f); 
}
