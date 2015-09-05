#include <stdlib.h> 
#include "snake.h"

void 
init_snake_head(SDL_Rect *head) 
{
	int win_width, win_height;

	SDL_GetWindowSize(ds.win, &win_width, &win_height);  // ds defined in main.c

	head = malloc(sizeof(SDL_Rect) * s.max_len);
	head->x = win_width / 2;
	head->y = win_height / 2;
	head->w = SNAKE_BLOCK_LEN;
	head->h = SNAKE_BLOCK_LEN;
}

struct snake
snake(void) 
{
	struct snake s;

	s.len = SNAKE_INIT_LEN; 
	s.max_len = SNAKE_INIT_MAX_LEN; 
	s.buff.st = EMPTY;
	init_snake_head(s.head);

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
move_snake(struct snake *s) // (!)
{
	SDL_Rect *block;
		
	block = s->head + s->len - 1; 	
	for(; block != s->head; block--) 
		*block = *(block - 1);

	switch(snake->dir) {

	case UP:
		head->y--;
		break;
	case DOWN:
		head->y++;	
		break;
	case LEFT:
		head->x--;	
		break;
	case RIGHT:
		head->x++;
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
	SDL_Rect *tail;
		
	tail = s->head + s->len - 1;
        *tail = s->buff.block;
	s->buff.st = EMPTY;
	s->len++; 
}

void
queue_block(struct snake *s) 
{
	SDL_Rect *tail = s->head + s->len - 1;

	s->buff.block = *tail;
	s->buff.st = FULL;
}


