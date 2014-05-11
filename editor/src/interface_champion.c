/*
** interface3.c for rush in /home/deffon_k/rendu/rush2/src
**
** Made by deffontaine kevin
** Login   <deffon_k@epitech.net>
**
** Started on  Sat May 10 23:21:34 2014 deffontaine kevin
** Last update Sun May 11 20:04:22 2014 Geoffrey Merran
*/

#include "parser.h"

void		create_att_champion(t_winChampion *winchampion)
{
  winchampion->labelWin[1] = gtk_label_new("Name");
  winchampion->attEntry[0] = gtk_entry_new_with_max_length(20);
  winchampion->labelWin[2] = gtk_label_new("Type");
  winchampion->combo_box = gtk_combo_box_new_text();
  gtk_combo_box_append_text(GTK_COMBO_BOX(winchampion->combo_box), "WARRIOR");
  gtk_combo_box_append_text(GTK_COMBO_BOX(winchampion->combo_box), "WIZARD");
  gtk_combo_box_append_text(GTK_COMBO_BOX(winchampion->combo_box), "TEMPLAR");
  winchampion->labelWin[3] = gtk_label_new("Health Points");
  winchampion->attEntry[2] = gtk_entry_new_with_max_length(20);
  winchampion->labelWin[4] = gtk_label_new("Special");
  winchampion->attEntry[3] = gtk_entry_new_with_max_length(20);
  winchampion->labelWin[5] = gtk_label_new("Speed");
  winchampion->attEntry[4] = gtk_entry_new_with_max_length(20);
  winchampion->labelWin[6] = gtk_label_new("Damage");
  winchampion->attEntry[5] = gtk_entry_new_with_max_length(20);
  winchampion->labelWin[7] = gtk_label_new("Weapon");
  winchampion->attEntry[6] = gtk_entry_new_with_max_length(20);
  winchampion->labelWin[8] = gtk_label_new("Armor");
  winchampion->attEntry[7] = gtk_entry_new_with_max_length(20);
}

void		pos_att_champion(t_winChampion *winchampion)
{
  int		i;

  i = 0;
  while (i < 8)
    {
      if (i == 1)
	{
	  gtk_table_attach_defaults(GTK_TABLE(winchampion->tableWin),
				    winchampion->labelWin[i + 1],
				    1, 2, i + 1, i + 2);
	  gtk_table_attach_defaults(GTK_TABLE(winchampion->tableWin),
				    winchampion->combo_box,
				    2, 3, i + 1, i + 2);
	}
      else
	{
	  gtk_table_attach_defaults(GTK_TABLE(winchampion->tableWin),
				    winchampion->labelWin[i + 1],
				    1, 2, i + 1, i + 2);
	  gtk_table_attach_defaults(GTK_TABLE(winchampion->tableWin),
				    winchampion->attEntry[i],
				    2, 3, i + 1, i + 2);
	}
      i++;
    }
}

void		init_winchampion(t_winChampion *winchampion)
{
  winchampion->labelWin[0] = gtk_label_new("Champion Editor");
  winchampion->labelWin[9] = gtk_label_new("");
  winchampion->winButton[0] = gtk_button_new_with_label("Add");
  winchampion->winButton[1] = gtk_button_new_with_label("Previous");
  winchampion->tableWin = gtk_table_new(12, 4, TRUE);
  gtk_container_add(GTK_CONTAINER(winchampion->mainWindow),
		    GTK_WIDGET(winchampion->tableWin));
  create_att_champion(winchampion);
  pos_att_champion(winchampion);
  gtk_table_attach_defaults(GTK_TABLE(winchampion->tableWin),
			    winchampion->labelWin[0],
			    1, 3, 0, 1);
  gtk_table_attach(GTK_TABLE(winchampion->tableWin), winchampion->winButton[0],
		   1, 2, 9, 10,
		   GTK_EXPAND | GTK_FILL, GTK_EXPAND,
		   0, 0);
  gtk_table_attach(GTK_TABLE(winchampion->tableWin), winchampion->winButton[1],
		   2, 3, 9, 10,
		   GTK_EXPAND | GTK_FILL, GTK_EXPAND,
		   0, 0);
  gtk_table_attach_defaults(GTK_TABLE(winchampion->tableWin),
			    winchampion->labelWin[9],
			    0, 4, 10, 11);
}

void		on_clicked_next_champ(GtkWidget *prevButton, t_winChampion *data)
{
  GtkWidget	*temp;

  (void) prevButton;
  gtk_widget_destroy(data->tableWin);
  gtk_main_quit();
  temp = data->mainWindow;
  free(data);
  create_window(temp);
}

void		create_winchampion(GtkWidget *mainWindow)
{
  t_winChampion	*winchampion;

  winchampion = my_xmalloc(sizeof(*winchampion));
  winchampion->mainWindow = mainWindow;
  init_winchampion(winchampion);
  g_signal_connect(G_OBJECT(winchampion->winButton[0]), "clicked",
		   G_CALLBACK(on_clicked_add_champ), winchampion);
  g_signal_connect(G_OBJECT(winchampion->winButton[1]), "clicked",
		   G_CALLBACK(on_clicked_next_champ), winchampion);
  gtk_widget_show_all(winchampion->mainWindow);
  gtk_main();
}
