#ifndef FOOD
#define FOOD

#include "coord.h"

struct food {
       char	    	symbol; 
       struct coord 	pos; 
};


struct food
food( void );

void 
move_food(struct food*); 

void
draw_food(struct food*);

#endif
