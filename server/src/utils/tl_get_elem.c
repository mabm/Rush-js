/*
** tl_get_elem.c for rush-js in /home/fourri_l/rendu/Rush-js/server
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sun May 11 18:11:49 2014 Laurent Fourrier
** Last update Sun May 11 18:24:10 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include <tlist.h>

void		*tl_get_elem(t_list *list, void *data, tl_func_cmp func)
{
  t_list	*cur;

  cur = list;
  while (cur)
    {
      if (func(data, cur->data) == 0)
	return (cur->data);
      cur = cur->next;
    }
  return (NULL);
}
