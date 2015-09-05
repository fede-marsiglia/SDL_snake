#include "msgs.h"
#include "snake.h"
#include "food.h"


struct draw_sys ds = def_draw_sys();

int 
main(void)
{
       struct snake s = snake();
       struct food f = food();

       while(1) {
	       draw_scene(ds);

	       move_snake(s);
	       if(s->buff.st == FULL)
		       add_block(s);

	       if(eat(s->head, f->pos)) {
		       queue_block(s);
		       move_food(f);
	       } 

	       update_scene(ds, s, f);
       }

       SDL_Quit();
       return 0;
}



