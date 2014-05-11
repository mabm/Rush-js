/*
** interpret_client_cmd.c for rush in /home/fouhet_k/Perso/Rush_10_may/src/client/choice_champ
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Sun May 11 15:33:50 2014 Kevin Fouhety
** Last update Sun May 11 16:23:01 2014 
*/

#include "client_monster.h"
#include "client_champ.h"
#include "client_interpret.h"

void	check_cmd_client(char *str, char *buff)
{
  if (strncmp(str, "list_monster", 12) == 0)
    show_monster_list(buff);
  else if (strncmp(str, "list_team", 9) == 0)
    show_champ_list(buff);
  else if (strncmp(str, "attack", 6) == 0)
    client_interpret_attack(buff);
  else if (strncmp(str, "attack_spe", 10) == 0)
    client_interpret_attack(buff);
  else if (strncmp(str, "who", 3) == 0)
    client_interpret_who(buff);
  else if (strncmp(str, "next", 4) == 0)
    client_interpret_next(buff);
}
