/*
** SDL.c for allum1 in /home/heitzl_s/rendu/Allum1/BONUS/sources
**
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
**
** Started on  Sun Feb  9 11:00:49 2014 Serge Heitzler
** Last update Sun May 11 18:01:08 2014 Nicolas Charvoz
*/

#include "../hdr/sdl.h"

void	quit_game(t_main *m)
{
  (void)m;
  //Free_SDL(m);
  SDL_Quit();
  exit(0);
}

void    key_pressed(t_main *m, t_choice *c)
{
  (void)c;
  switch (m->event.key.keysym.sym)
    {
    case SDLK_ESCAPE:
      quit_game(m);
      break;
    default:
      break;
    }
}
