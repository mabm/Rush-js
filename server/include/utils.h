/*
** utils.h for rush-js in /home/fourri_l/rendu/Rush-js/server
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sat May 10 16:49:50 2014 Laurent Fourrier
** Last update Sun May 11 18:23:49 2014 Laurent Fourrier
*/

#ifndef UTILS_H_
# define UTILS_H_

# include <tlist.h>

char	*read_string(char *line);

char	**str_to_wordarr(char *str, char *seps);

/*
** List getter
*/
void	*tl_get_elem(t_list *list, void *data, tl_func_cmp func);

#endif
