/*
** interface4.c for interface4 in /home/merran_g/work/c_elem/rush2/src
**
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
**
** Started on  Sat May 10 22:14:18 2014 Geoffrey Merran
** Last update Sun May 11 01:24:21 2014 Geoffrey Merran
*/

#include "parser.h"

void		create_att_room(t_winRoom *winroom)
{
  winroom->labelWin[1] = gtk_label_new("Name");
  winroom->attEntry[0] = gtk_entry_new_with_max_length(20);
  winroom->labelWin[2] = gtk_label_new("Avantage");
  winroom->attEntry[1] = gtk_entry_new_with_max_length(20);
  winroom->labelWin[3] = gtk_label_new("Access");
  winroom->attEntry[2] = gtk_entry_new_with_max_length(20);
  winroom->labelWin[4] = gtk_label_new("Mobs");
  winroom->attEntry[3] = gtk_entry_new_with_max_length(20);
}



void		pos_att_room(t_winRoom *winroom)
{
  int		i;

  i = 0;
  while (i < 4)
    {
      gtk_table_attach_defaults(GTK_TABLE(winroom->tableWin),
				winroom->labelWin[i + 1],
				1, 2, i + 1, i + 2);
      gtk_table_attach_defaults(GTK_TABLE(winroom->tableWin),
				winroom->attEntry[i],
				2, 3, i + 1, i + 2);
      i++;
    }
}

void		init_winroom(t_winRoom *winroom)
{
  winroom->labelWin[0] = gtk_label_new("Room Editor");
  winroom->winButton[0] = gtk_button_new_with_label("Add");
  winroom->winButton[1] = gtk_button_new_with_label("Previous");
  winroom->tableWin = gtk_table_new(7, 4, TRUE);
  gtk_container_add(GTK_CONTAINER(winroom->mainWindow),
		    GTK_WIDGET(winroom->tableWin));
  create_att_room(winroom);
  pos_att_room(winroom);
  gtk_table_attach_defaults(GTK_TABLE(winroom->tableWin),
				winroom->labelWin[0],
				1, 3, 0, 1);
  gtk_table_attach(GTK_TABLE(winroom->tableWin), winroom->winButton[0],
		   1, 2, 5, 6,
		   GTK_EXPAND | GTK_FILL, GTK_EXPAND,
		   0, 0);
  gtk_table_attach(GTK_TABLE(winroom->tableWin), winroom->winButton[1],
		   2, 3, 5, 6,
		   GTK_EXPAND | GTK_FILL, GTK_EXPAND,
		   0, 0);
}

void		on_clicked_previous_room(GtkWidget *prevButton, t_winRoom *data)
{
  GtkWidget	*temp;

  (void) prevButton;
  gtk_widget_destroy(data->tableWin);
  gtk_main_quit();
  temp = data->mainWindow;
  free(data);
  create_window(temp);
}

void		create_winroom(GtkWidget *mainWindow)
{
  t_winRoom	*winroom;

  winroom = my_xmalloc(sizeof(*winroom));
  winroom->mainWindow = mainWindow;
  init_winroom(winroom);
  g_signal_connect(G_OBJECT(winroom->winButton[1]), "clicked",
		   G_CALLBACK(on_clicked_previous_room), winroom);
  gtk_widget_show_all(winroom->mainWindow);
  gtk_main();
}
