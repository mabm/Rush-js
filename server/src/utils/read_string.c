/*
** read_string.c for rush-js in /home/fourri_l/rendu/Rush-js/server
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sat May 10 16:50:17 2014 Laurent Fourrier
** Last update Sat May 10 21:41:30 2014 Laurent Fourrier
*/

#include <unistd.h>
#include <stdlib.h>

char		*read_string(char *line)
{
  char		*rtn;
  int		it;
  char		len;

  len = line[0];
  line++;
  rtn = malloc(len + 1);
  if (!rtn)
    return (NULL);
  it = 0;
  while (it < len)
    {
      rtn[it] = line[it];
      it++;
    }
  rtn[it] = '\0';
  return (rtn);
}
