#include <stdlib.h>
#include "food.h"

struct food
food(void)
{
    struct food f;

    f.symbol = '@';
    f.pos.x = rand() % COLS;
    f.pos.y = rand() % LINES;

    return f;
}

void 
move_food(struct food *f) 
{
    f->pos.x = rand() % COLS;
    f->pos.y = rand() % LINES;

    mvaddch(f->pos.y, f->pos.x, f->symbol);
}

void
draw_food(struct food *f)
{
       /* sdl code here */
}
