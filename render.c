#include "render.h"
#include <SDL2/SDL.h>

void
draw_screen(struct game *g)
{
	SDL_SetRenderDrawColor(g->rend, 0, 0, 0, 0);
	SDL_RenderClear(g->rend);

	SDL_SetRenderDrawColor(g->rend, 0, 0xFF, 0, 0);
	SDL_RenderFillRects(g->rend, 
			    g->snake.head, 
			    g->snake.len);

	SDL_SetRenderDrawColor(g->rend, 0xFF, 0, 0, 0);
	SDL_RenderFillRect(g->rend,
			  &g->food);

	SDL_RenderPresent(g->rend);
};
