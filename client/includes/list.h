/*
** list.h for EPIC_JS_FANTASY in /home/cruvei_t/RUSH_PGM/client/includes
** 
** Made by 
** Login   <cruvei_t@epitech.net>
** 
** Started on  Sat May 10 21:43:16 2014 
** Last update Sat May 10 21:46:40 2014 
*/

#ifndef LIST_H_
#define LIST_H_

struct s_list
{
  char			*command;
  struct	s_list	*next;
  struct	s_list	*previous;
};
typedef struct s_list t_list;

#endif
