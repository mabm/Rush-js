/*
** visualizer.c for  in /home/charvo_a/rush/visualizer/src
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Sun May 11 22:07:30 2014 Nicolas Charvoz
** Last update Sun May 11 22:07:32 2014 Nicolas Charvoz
*/

#include "../hdr/sdl.h"

int	visu_menu(t_list_champ **list)
{
  t_main	*m;
  t_champ	*champ;
  t_choice	*c;

  m = malloc(sizeof(*m));
  c = malloc(sizeof(*c));
  champ = malloc(6 * sizeof(*champ));
  init_SDL(m, champ, c, *list);
  return (0);
}
