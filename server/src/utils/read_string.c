/*
** read_string.c for rush-js in /home/fourri_l/rendu/Rush-js/server
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sat May 10 16:50:17 2014 Laurent Fourrier
** Last update Sat May 10 20:21:19 2014 Nicolas Ades
*/

#include <unistd.h>
#include <stdlib.h>

char		*read_string(int fd)
{
  char		*rtn;
  unsigned char	len;

  if (read(fd, &len, 1) < 1)
    return (NULL);
  rtn = malloc(len + 1);
  if (!rtn)
    return (NULL);
  if (read(fd, &rtn, len) < 1)
    {
      free(rtn);
      return (NULL);
    }
  rtn[len + 1] = '\0';
  return (rtn);
}
