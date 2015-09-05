#ifndef SNAKE
#define SNAKE

#define SNAKE_BLOCK_LEN 	50
#define SNAKE_INIT_LEN 		1
#define SNAKE_INIT_MAX_LEN	10

struct buffer {
       enum {EMPTY, FULL}	st;
       SDL_Rect 		block;
};

struct snake {
       int		       len;				
       int		       max_len;
       SDL_Rect	      	       *head;
       struct buffer	       buff;	/* "to add" block buffer */	
};

void
init_snake_head(void);

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

#endif

