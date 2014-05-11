/*
** interface_add.c for interface_add in /home/merran_g/work/c_elem/epic_js_fantasy/editor/src
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Sun May 11 03:01:32 2014 Geoffrey Merran
** Last update Sun May 11 16:50:23 2014 Geoffrey Merran
*/

#include "parser.h"

void		on_clicked_add_champ(GtkWidget *addButton, t_winChampion *data)
{
  (void) addButton;
  add_champion(data, &game->champs);
}

void		on_clicked_add_monster(GtkWidget *addButton, t_winMonster *data)
{
  (void) addButton;
  add_monster(data, &game->monsters);
}

void		on_clicked_add_room(GtkWidget *addButton, t_winRoom *data)
{
  (void) addButton;
  add_room(data, &game->rooms);
}
