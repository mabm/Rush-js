/*
** game.c for  in /home/charvo_a/rush/visualizer/game
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Sun May 11 22:27:05 2014 Nicolas Charvoz
** Last update Sun May 11 23:47:03 2014 Nicolas Charvoz
*/

#include "./hdr/game.h"
#include "test.h"

int		main() /*MAIN GAME */
{
  t_game	*g;
  t_player	*p;
  t_monster	*m;
  t_champ	*c;


  c = malloc(sizeof(*c));
  p = malloc(6 * sizeof(*p));
  g = malloc(sizeof(*g));
  m = malloc(6 * sizeof(*m));
  SDL_Init(SDL_INIT_VIDEO);
  TTF_Init();
  g->ecran = NULL;
  g->ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  SDL_WM_SetCaption("MAP GAME TEAM EPITECH 2018", NULL);
  init_sdl(c, g, p, m);
  return (0);
}
