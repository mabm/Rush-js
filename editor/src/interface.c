/*
** interface.c for interface in /home/merran_g/work/c_elem/rush2/src
**
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
**
** Started on  Sat May 10 16:30:59 2014 Geoffrey Merran
** Last update Sun May 11 19:50:58 2014 Geoffrey Merran
*/

#define _BSD_SOURCE
#include "parser.h"

void		init_button_winmap(t_winMap *winmap)
{
  gtk_table_attach(GTK_TABLE(winmap->tableWin), winmap->winButton[0],
		   2, 3, 4, 5,
		   GTK_EXPAND | GTK_FILL, GTK_EXPAND,
		   0, 10);
  gtk_table_attach(GTK_TABLE(winmap->tableWin), winmap->winButton[1],
		   1, 2, 3, 4,
		   GTK_EXPAND | GTK_FILL, GTK_EXPAND,
		   0, 0);
  gtk_table_attach(GTK_TABLE(winmap->tableWin), winmap->winButton[2],
		   2, 3, 3, 4,
		   GTK_EXPAND | GTK_FILL, GTK_EXPAND,
		   10, 0);
  gtk_table_attach(GTK_TABLE(winmap->tableWin), winmap->winButton[3],
		   3, 4, 3, 4,
		   GTK_EXPAND | GTK_FILL, GTK_EXPAND,
		   0, 0);
}

void		init_winmap(t_winMap *winmap)
{
  winmap->labelWin[0] = gtk_label_new("Epic Editor");
  winmap->labelWin[1] = gtk_label_new("Map Name");
  winmap->labelWin[2] = gtk_label_new("");
  winmap->winButton[0] = gtk_button_new_with_label("Create Map");
  winmap->winButton[1] = gtk_button_new_with_label("Monster Editor");
  winmap->winButton[2] = gtk_button_new_with_label("Champion Editor");
  winmap->winButton[3] = gtk_button_new_with_label("Room Editor");
  winmap->tableWin = gtk_table_new(6, 5, TRUE);
  winmap->mapEntry = gtk_entry_new_with_max_length(20);
  gtk_container_add(GTK_CONTAINER(winmap->mainWindow),
		    GTK_WIDGET(winmap->tableWin));
  gtk_table_attach_defaults(GTK_TABLE(winmap->tableWin), winmap->labelWin[0],
		   2, 3, 0, 1);
  gtk_table_attach_defaults(GTK_TABLE(winmap->tableWin), winmap->labelWin[1],
		   2, 3, 1, 2);
  gtk_table_attach_defaults(GTK_TABLE(winmap->tableWin), winmap->mapEntry,
		   2, 3, 2, 3);
  gtk_table_attach_defaults(GTK_TABLE(winmap->tableWin), winmap->labelWin[2],
  		   0, 5, 5, 6);
  init_button_winmap(winmap);
}

void		on_clicked_createbutton(GtkWidget *button, t_winMap *data)
{
  const gchar  	*text;

  (void) button;
  text = gtk_entry_get_text(GTK_ENTRY(data->mapEntry));
  if (text != NULL && text[0] != '\0')
    {
      game->header->name = strdup((char *) text);
      printf("MapName changed to [%s]\n", text);
      if (game->header->start_room != NULL &&
	  game->header->end_room != NULL &&
	  game->champs != NULL &&
	  game->monsters != NULL)
	{
	  gtk_widget_destroy(data->mainWindow);
	  gtk_main_quit();
	  create_map();
	}
      else
	gtk_label_set_text(GTK_LABEL(data->labelWin[2]),
			   "Need one start room, end room, one champ and one monster\n");
    }
}

void		on_clicked_nextbutton(GtkWidget *button, t_winMap *data)
{
  GtkWidget	**winButton;
  GtkWidget	*temp;

  winButton = data->winButton;
  gtk_widget_destroy(data->tableWin);
  gtk_main_quit();
  temp = data->mainWindow;
  free(data);
  if (button == winButton[1])
    create_winmonster(temp);
  if (button == winButton[2])
    create_winchampion(temp);
  if (button == winButton[3])
    create_winroom(temp);
}

void		create_window(GtkWidget *mainWindow)
{
  t_winMap	*winmap;

  winmap = my_xmalloc(sizeof(*winmap));
  winmap->mainWindow = mainWindow;
  init_winmap(winmap);
  g_signal_connect(G_OBJECT(winmap->winButton[0]), "clicked",
		   G_CALLBACK(on_clicked_createbutton), winmap);
  g_signal_connect(G_OBJECT(winmap->winButton[1]), "clicked",
		   G_CALLBACK(on_clicked_nextbutton), winmap);
  g_signal_connect(G_OBJECT(winmap->winButton[2]), "clicked",
		   G_CALLBACK(on_clicked_nextbutton), winmap);
  g_signal_connect(G_OBJECT(winmap->winButton[3]), "clicked",
		   G_CALLBACK(on_clicked_nextbutton), winmap);
  gtk_widget_show_all(winmap->mainWindow);
  gtk_main();
}
