/*
** check_rooms_errors.c for  in /home/mediav_j/mabm/rush/editor/src
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Sun May 11 19:33:43 2014 Jeremy Mediavilla
** Last update Sun May 11 20:16:51 2014 Jeremy Mediavilla
*/

#define _BSD_SOURCE
#include "parser.h"

char		*check_error_button1()
{
  char		*err_msg;

  if (game->header->start_room == NULL)
    return (NULL);
  err_msg = strdup("Room : ");
  err_msg = strcat(err_msg, strdup(game->header->start_room->name));
  err_msg = strcat(err_msg, strdup(" is already the starting room"));
  return (err_msg);
}

char		*check_error_button2()
{
  char		*err_msg;

  if (game->header->end_room == NULL)
    return (NULL);
  err_msg = strdup("Room : ");
  err_msg = strcat(err_msg, strdup(game->header->end_room->name));
  err_msg = strcat(err_msg, strdup(" is already the ending room"));
  return (err_msg);
}

int		is_already_this_room(char *name)
{
  t_room	*tmp;

  tmp = game->rooms;
  while (tmp != NULL)
    {
      if (strcmp(tmp->name, name) == 0)
	return (1);
      tmp = tmp->next;
    }
  return (0);
}

char		*check_room_error(t_winRoom *data)
{
  const gchar	*text;
  char		*error;

  text = gtk_entry_get_text(GTK_ENTRY(data->attEntry[0]));
  if (text[0] == '\0')
    return ("Missing room name");
  else if (is_already_this_room((char *) text) == 1)
    return ("This room already exist");
  text = gtk_entry_get_text(GTK_ENTRY(data->attEntry[1]));
  if (text[0] == '\0')
    gtk_entry_set_text(GTK_ENTRY(data->attEntry[1]), "NONE");
  text = gtk_entry_get_text(GTK_ENTRY(data->attEntry[2]));
  if (text[0] == '\0')
    gtk_entry_set_text(GTK_ENTRY(data->attEntry[2]), "NONE");
  text = gtk_entry_get_text(GTK_ENTRY(data->attEntry[3]));
  if (text[0] == '\0')
    gtk_entry_set_text(GTK_ENTRY(data->attEntry[3]), "NONE");
  if (GTK_TOGGLE_BUTTON(G_OBJECT(data->checkButton[0]))->active &&
      (GTK_TOGGLE_BUTTON(G_OBJECT(data->checkButton[1]))->active))
    return ("The room couldn't be the start AND the end room");
  if ((error = check_error_button1()) != NULL)
    return (error);
  if ((error = check_error_button2()) != NULL)
    return (error);
  return (NULL);
}
