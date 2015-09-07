#ifndef SNAKE
#define SNAKE

#include <stdbool.h>
#include <SDL2/SDL.h>

#define SNAKE_BLOCK_LEN 	10
#define SNAKE_INIT_LEN 		1
#define SNAKE_INIT_MAX_LEN	10

enum direction { 
	UP =	 SDLK_w,
	DOWN = 	 SDLK_s,
	LEFT = 	 SDLK_a,
	RIGHT =  SDLK_d
};

struct buffer {
       enum {EMPTY, FULL}	st;
       SDL_Rect 		block;
};

struct snake {
       int		       len;				
       int		       max_len;
       SDL_Rect	      	       *head;
       struct buffer	       buff;	/* "to be added" block buffer */	
       enum direction	       dir;
};

struct snake
snake(void); 

void
extend(struct snake*); 

void
move_snake(struct snake*);

bool 
full(struct snake*);

void
add_block(struct snake*);

void
queue_block(struct snake*); 

SDL_bool 
eat_food(struct snake*, 
	 SDL_Rect *food);

bool
eat_himself(struct snake*);

#endif

