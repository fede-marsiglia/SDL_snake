#define draw_sys.h

struct draw_sys 
def_draw_sys(void)
{
	static struct draw_sys ds;

	ds.win = SDL_CreateWindow("sample",
				  SDL_WINDOWPOS_UNDEFINED,
				  SDL_WINDOWPOS_UNDEFINED,
				  DRAW_SYS_WIN_WIDTH,
				  DRAW_SYS_WIN_HEIGHT,
				  SDL_WINDOW_RESIZABLE);

	ds.rend = SDL_CreateRenderer(ds.win, 0, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(ds.rend, 0, 0, 0, 0);	/* color is black */
	SDL_RenderClear(ds);	/* paint window backgr in black */

	return ds;
}

void 
draw_sys_free(struct draw_sys *ds)
{
	SDL_DestroyWindow(ds->win);
	SDL_DestroyRenderer(ds->rend);
}

void
draw_scene(SDL_Renderer *r)
{

}
