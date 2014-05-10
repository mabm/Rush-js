/*
** str_to_wordarr.c for rush-js in /home/fourri_l/rendu/Rush-js/server
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sat May 10 16:58:49 2014 Laurent Fourrier
** Last update Sat May 10 20:30:06 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include <string.h>

static char	is_separator(char c, char *seps)
{
  while (*seps)
    {
      if (*seps++ == c)
	return (1);
    }
  return (0);
}

static int	get_wordarr_len(char *str, char *seps)
{
  char		in_word;
  int		rtn;

  rtn = 0;
  in_word = 0;
  while (*str)
    {
      if ((in_word ^ is_separator(*str, seps)) == 0)
	{
	  in_word = !in_word;
	  if (in_word)
	    rtn++;
	}
    }
  return (rtn);
}

char		**str_to_wordarr(char *str, char *seps)
{
  char		**rtn;
  int		it;

  rtn = malloc(get_wordarr_len(str, seps) * sizeof(void*));
  if (!rtn)
    return (NULL);
  it = 0;
  while ((rtn[it++] = strtok(str, seps)) != NULL)
    str = NULL;
  rtn[it] = NULL;
  return (rtn);
}
