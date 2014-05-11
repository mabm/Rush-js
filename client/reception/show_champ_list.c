/*
** show_champ_list.c for rush in /home/fouhet_k/Perso/Rush_10_may/src/client/choice_champ
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Sat May 10 18:40:18 2014 Kevin Fouhety
** Last update Sat May 10 20:11:51 2014 Kevin Fouhety
*/

#include "client_champ.h"

void    show_champ_list(char *buff)
{
  t_list_champ  *list_champ;
  char          **tmp;

  tmp = parsing_cmd(buff);
  list_champ = creat_list_champ(tmp);
  display_choice(list_champ);
  free_list_champ(list_champ);
  free_tab(tmp);
}
