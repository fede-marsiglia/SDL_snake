#include "game.h"

int 
main(void)
{ 
       SDL_SetMainReady();
       SDL_Init(SDL_INIT_VIDEO);	

       struct game g = game();
       game_start(&g);
       free_resources(&g);

       SDL_Quit();
       return 0;
}



