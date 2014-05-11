/*
** interface_add.c for interface_add in /home/merran_g/work/c_elem/epic_js_fantasy/editor/src
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Sun May 11 03:01:32 2014 Geoffrey Merran
** Last update Sun May 11 21:39:52 2014 Geoffrey Merran
*/

#include "parser.h"

void		on_clicked_add_champ(GtkWidget *addButton, t_winChampion *data)
{
  char		*error;

  (void) addButton;
  error = check_champ_errors(data);
  if (error == NULL)
    {
      add_champion(data, &game->champs);
      gtk_label_set_text(GTK_LABEL(data->labelWin[9]), "");
    }
  else
    gtk_label_set_text(GTK_LABEL(data->labelWin[9]), error);
}

void		on_clicked_add_monster(GtkWidget *addButton, t_winMonster *data)
{
  char		*error;

  (void) addButton;
  error = check_monst_errors(data);
  if (error == NULL)
    {
      add_monster(data, &game->monsters);
      gtk_label_set_text(GTK_LABEL(data->labelWin[8]), "");
    }
  else
    gtk_label_set_text(GTK_LABEL(data->labelWin[8]), error);
}

void		on_clicked_add_room(GtkWidget *addButton, t_winRoom *data)
{
  char		*error;

  (void) addButton;
  error = check_room_error(data);
  if (error == NULL)
    add_room(data, &game->rooms);
  else
    printf("%s\n", error);
}
