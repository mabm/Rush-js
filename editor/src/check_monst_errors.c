/*
** check_monst_errors.c for  in /home/mediav_j/mabm/rush/editor/src
** 
** Made by Jeremy Mediavilla
** Login   <mediav_j@epitech.net>
** 
** Started on  Sun May 11 18:51:12 2014 Jeremy Mediavilla
** Last update Sun May 11 19:25:46 2014 Jeremy Mediavilla
*/

#include "parser.h"


char		*is_valid_stats2(t_winMonster *data, int i, int j)
{
  const gchar	*text;

  while (i < j)
    {
      text = gtk_entry_get_text(GTK_ENTRY(data->attEntry[i]));
      if (my_str_isnum((char *) text) != 1)
	return ("Bad Monster stats (hp/spe/speed/deg)");
      i++;
    }
  return (NULL);
}

int		is_already_monst(char *type)
{
  t_monster	*tmp;

  tmp = game->monsters;
  while (tmp != NULL)
    {
      if (strcmp(tmp->type, type) == 0)
	return (1);
      tmp = tmp->next;
    }
  return (0);
}

char		*check_monst_errors(t_winMonster *data)
{
  char		*error;
  const gchar	*text;

  text = gtk_entry_get_text(GTK_ENTRY(data->attEntry[0]));
  if (text[0] == '\0')
    return ("Missing Monster name");
  else if (is_already_monst((char *) text) == 1)
    return ("This monster type already exist");
  if ((error = is_valid_stats2(data, 1, 4)) != NULL)
    return (error);
  text = gtk_entry_get_text(GTK_ENTRY(data->attEntry[5]));
  if (text[0] == '\0')
    gtk_entry_set_text(GTK_ENTRY(data->attEntry[5]), "NONE");
  text = gtk_entry_get_text(GTK_ENTRY(data->attEntry[6]));
  if (text[0] == '\0')
    gtk_entry_set_text(GTK_ENTRY(data->attEntry[6]), "NONE");
  return (NULL);
}
