/*
** img_blit.c for  in /home/charvo_a/rush/visualizer/game
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Sun May 11 23:00:34 2014 Nicolas Charvoz
** Last update Sun May 11 23:55:03 2014 Nicolas Charvoz
*/

#include "./hdr/game.h"

void	my_pause()
{
  int	continuer = 1;
  SDL_Event	event;

  while (continuer)
    {
      SDL_WaitEvent(&event);
      switch(event.type)
        {
	case SDL_QUIT:
	  continuer = 0;
        }
    }
}


void	img_blit(t_game *g, t_player *p, t_monster *m)
{
  g->pos_next.x = 685;
  g->pos_next.y = 540;
  g->pos_map.x = 0;
  g->pos_map.y = 0;
  g->pos_prev.x = 0;
  g->pos_prev.y = 540;
  p->pos_skin.x = 380;
  p->pos_skin.y = 100;
  SDL_BlitSurface(g->map, NULL, g->ecran, &g->pos_map);
  SDL_BlitSurface(g->next, NULL, g->ecran, &g->pos_next);
  SDL_BlitSurface(g->prev, NULL, g->ecran, &g->pos_prev);
  SDL_BlitSurface(p->skin, NULL, g->ecran, &p->pos_skin);
  SDL_Flip(g->ecran);
  pause();
}
