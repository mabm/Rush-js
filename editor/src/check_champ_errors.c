/*
** check_errors.c for  in /home/mediav_j/mabm/rush/editor/src
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Sun May 11 17:59:00 2014 Jeremy Mediavilla
** Last update Sun May 11 19:05:31 2014 Jeremy Mediavilla
*/

#include "parser.h"

char		*is_valid_stats(t_winChampion *data, int i, int j)
{
  const gchar	*text;

  while (i < j)
    {
      text = gtk_entry_get_text(GTK_ENTRY(data->attEntry[i]));
      if (my_str_isnum((char *) text) != 1)
	return ("Bad Champion stats (hp/spe/speed/deg)");
      i++;
    }
  return (NULL);
}

char		*check_champ_errors(t_winChampion *data)
{
  char		*error;
  const gchar	*text;

  text = gtk_entry_get_text(GTK_ENTRY(data->attEntry[0]));
  if (text[0] == '\0')
    return ("Missing Champion name");
  text = gtk_combo_box_get_active_text(GTK_COMBO_BOX(data->combo_box));
  if (text == NULL)
    return ("Missing Champion type");
  if ((error = is_valid_stats(data, 2, 5)) != NULL)
    return (error);
  text = gtk_entry_get_text(GTK_ENTRY(data->attEntry[6]));
  if (text[0] == '\0')
    gtk_entry_set_text(GTK_ENTRY(data->attEntry[6]), "NONE");
  text = gtk_entry_get_text(GTK_ENTRY(data->attEntry[7]));
  if (text[0] == '\0')
    gtk_entry_set_text(GTK_ENTRY(data->attEntry[7]), "NONE");
  return (NULL);
}
