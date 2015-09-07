#include "game.h"
#include "render.h"
#include "IO.h"
#include <stdbool.h>

struct game
game(void)
{
	struct game g;

	g.snake = snake();
	g.food = food();
	SDL_CreateWindowAndRenderer(DEF_WIN_WIDTH,
				    DEF_WIN_HEIGHT,
				    SDL_WINDOWPOS_CENTERED,
				    &g.win,
				    &g.rend);
	return g;
}

void
game_start(struct game *g)
{
	bool running = true;

	while(running) {
		draw_screen(g);

		while(SDL_PollEvent(&g->event))
			if(snake_dir_change(&g->event))
				g->snake.dir = g->event.key.keysym.sym;

		if(eat_food(&g->snake, &g->food)) {
			move_food(&g->food);
			queue_block(&g->snake);
		}
		
		move_snake(&g->snake);
		if(g->snake.buff.st == FULL) 
			add_block(&g->snake); 
		if(eat_himself(&g->snake)) 
			running = false;
		SDL_Delay(50);
	}
}

void
free_resources(struct game *g)
{
	SDL_DestroyWindow(g->win);
	SDL_DestroyRenderer(g->rend);
}




