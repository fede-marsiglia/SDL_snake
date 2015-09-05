#include <SDL.h>
#include <SDL_video.h>

#define DRAW_SYS_WIN_HEIGHT	480
#define DRAW_SYS_WIN_WIDTH	640

struct draw_sys { 
	SDL_Window 	*win
	SDL_Renderer 	*rend;
}

struct draw_sys
def_draw_sys(void)

void
check_draw_sys_init(void); // (!)

void
draw_sys_free(struct draw_sys*);
