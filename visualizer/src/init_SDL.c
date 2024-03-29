/*
** init_SDL.c for  in /home/charvo_a/visualizer
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Sun May 11 17:44:34 2014 Nicolas Charvoz
** Last update Sun May 11 18:00:35 2014 Nicolas Charvoz
*/

#include "../hdr/sdl.h"

void	first_init_SDL(t_main *m, t_choice *c)
{
  (void)c;
  SDL_Init(SDL_INIT_VIDEO);
  TTF_Init();
  m->ecran = NULL;
  m->cursor = NULL;
  SDL_putenv("SDL_VIDEO_CENTERED=center");
  m->ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  SDL_WarpMouse((m->ecran->w / 2), (m->ecran->h / 2));
  SDL_WM_SetCaption("OH MY RPG - EPITECH NICE - RUSH 2014", NULL);
}

void	init_SDL(t_main *m, t_champ *champ, t_choice *c)
{
  first_init_SDL(m, c);
  img_load_menu(m, c);
  init_champions(m, champ, c);
}
