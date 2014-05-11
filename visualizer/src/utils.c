/*
** utils.c for  in /home/charvo_a/rush/visualizer/src
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Sun May 11 22:07:23 2014 Nicolas Charvoz
** Last update Sun May 11 22:07:25 2014 Nicolas Charvoz
*/

#include "../hdr/sdl.h"

int	center_text(char *str)
{
  int	i;
  int	a;

  i = 11;
  a = strlen(str);
  a = 0.5 * i * a;
  return (a * (-1));
}
