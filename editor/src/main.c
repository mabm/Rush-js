/*
** main.c for  in /home/merran_g/work/c_piscine/mkdir
**
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
**
** Started on  Fri Oct  4 09:11:03 2013 Geoffrey Merran
** Last update Sun May 11 01:40:54 2014 Geoffrey Merran
*/

#include "parser.h"

t_game	*game;

void		init_window(GtkWidget **mainWindow)
{
  *mainWindow = NULL;
  *mainWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_default_size(GTK_WINDOW(*mainWindow), WIN_X,  WIN_Y);
  gtk_window_set_position(GTK_WINDOW(*mainWindow), GTK_WIN_POS_CENTER);
  gtk_window_set_title(GTK_WINDOW(*mainWindow), "Epic Editor");
  g_signal_connect(G_OBJECT(*mainWindow), "delete-event",
		   G_CALLBACK(gtk_main_quit), NULL);
}

void		launch_editor()
{
  GtkWidget	*mainWindow;

  init_window(&mainWindow);
  game = my_xmalloc(sizeof(*game));
  game->header = my_xmalloc(sizeof(*game->header));
  game->champs = NULL;
  game->monsters = NULL;
  game->rooms = NULL;
  create_window(mainWindow);
}

int	main(int ac, char **av)
{
  gtk_init(&ac, &av);
  if (ac == 1)
    launch_editor();
  else
    printf(EDITOR_USAGE);
  return (EXIT_SUCCESS);
}
