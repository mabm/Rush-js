/*
** interface_add.c for interface_add in /home/merran_g/work/c_elem/epic_js_fantasy/editor/src
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Sun May 11 03:01:32 2014 Geoffrey Merran
** Last update Sun May 11 19:09:39 2014 Geoffrey Merran
*/

#include "parser.h"

void		on_clicked_add_champ(GtkWidget *addButton, t_winChampion *data)
{
  char		*error;

  (void) addButton;
<<<<<<< HEAD

  add_champion(data, &game->champs);
=======
  error = check_champ_errors(data);
  if (error == NULL)
    add_champion(data, &game->champs);
  else
    printf("%s\n", error);
>>>>>>> 1c75aa441545211c3ce129b899ec0dd32f3ed1ae
}

void		on_clicked_add_monster(GtkWidget *addButton, t_winMonster *data)
{
  char		*error;

  (void) addButton;
  error = check_monst_errors(data);
  if (error == NULL)
    add_monster(data, &game->monsters);
  else
    printf("%s\n", error);
}

void		on_clicked_add_room(GtkWidget *addButton, t_winRoom *data)
{
  (void) addButton;
  add_room(data, &game->rooms);
}