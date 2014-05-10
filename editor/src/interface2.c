/*
** interface2.c for interface2 in /home/merran_g/work/c_elem/rush2/src
**
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
**
** Started on  Sat May 10 22:14:18 2014 Geoffrey Merran
** Last update Sun May 11 01:19:44 2014 Geoffrey Merran
*/

#include "parser.h"

void		create_att_monster(t_winMonster *winmonster)
{
  winmonster->labelWin[1] = gtk_label_new("Type");
  winmonster->attEntry[0] = gtk_entry_new_with_max_length(20);
  winmonster->labelWin[2] = gtk_label_new("Heath point");
  winmonster->attEntry[1] = gtk_entry_new_with_max_length(20);
  winmonster->labelWin[3] = gtk_label_new("Special");
  winmonster->attEntry[2] = gtk_entry_new_with_max_length(20);
  winmonster->labelWin[4] = gtk_label_new("Speed");
  winmonster->attEntry[3] = gtk_entry_new_with_max_length(20);
  winmonster->labelWin[5] = gtk_label_new("Damage");
  winmonster->attEntry[4] = gtk_entry_new_with_max_length(20);
  winmonster->labelWin[6] = gtk_label_new("Weapon");
  winmonster->attEntry[5] = gtk_entry_new_with_max_length(20);
  winmonster->labelWin[7] = gtk_label_new("Armor");
  winmonster->attEntry[6] = gtk_entry_new_with_max_length(20);
}

void		pos_att_monster(t_winMonster *winmonster)
{
  int		i;

  i = 0;
  while (i < 7)
    {
      gtk_table_attach_defaults(GTK_TABLE(winmonster->tableWin),
				winmonster->labelWin[i + 1],
				1, 2, i + 1, i + 2);
      gtk_table_attach_defaults(GTK_TABLE(winmonster->tableWin),
				winmonster->attEntry[i],
				2, 3, i + 1, i + 2);
      i++;
    }
}

void		init_winmonster(t_winMonster *winmonster)
{
  winmonster->labelWin[0] = gtk_label_new("Monster Editor");
  winmonster->winButton[0] = gtk_button_new_with_label("Add");
  winmonster->winButton[1] = gtk_button_new_with_label("Previous");
  winmonster->tableWin = gtk_table_new(10, 4, TRUE);
  gtk_container_add(GTK_CONTAINER(winmonster->mainWindow),
		    GTK_WIDGET(winmonster->tableWin));
  create_att_monster(winmonster);
  pos_att_monster(winmonster);
  gtk_table_attach_defaults(GTK_TABLE(winmonster->tableWin),
				winmonster->labelWin[0],
				1, 3, 0, 1);
  gtk_table_attach(GTK_TABLE(winmonster->tableWin), winmonster->winButton[0],
		   1, 2, 8, 9,
		   GTK_EXPAND | GTK_FILL, GTK_EXPAND,
		   0, 0);
  gtk_table_attach(GTK_TABLE(winmonster->tableWin), winmonster->winButton[1],
		   2, 3, 8, 9,
		   GTK_EXPAND | GTK_FILL, GTK_EXPAND,
		   0, 0);
}

void		on_clicked_add_monster(GtkWidget *addButton, t_winMonster *data)
{
  const gchar  	*text;

  (void) addButton;
  text = gtk_entry_get_text(GTK_ENTRY(data->attEntry[0]));
  printf("%s\n", text);
  text = gtk_entry_get_text(GTK_ENTRY(data->attEntry[1]));
  printf("%s\n", text);
  text = gtk_entry_get_text(GTK_ENTRY(data->attEntry[2]));
  printf("%s\n", text);
  text = gtk_entry_get_text(GTK_ENTRY(data->attEntry[3]));
  printf("%s\n", text);
  text = gtk_entry_get_text(GTK_ENTRY(data->attEntry[4]));
  printf("%s\n", text);
  text = gtk_entry_get_text(GTK_ENTRY(data->attEntry[5]));
  printf("%s\n", text);
  text = gtk_entry_get_text(GTK_ENTRY(data->attEntry[6]));
  printf("%s\n", text);
}

void		on_clicked_next_monster(GtkWidget *prevButton, t_winMonster *data)
{
  GtkWidget	*temp;

  (void) prevButton;
  gtk_widget_destroy(data->tableWin);
  gtk_main_quit();
  temp = data->mainWindow;
  free(data);
  create_window(temp);
}

void		create_winmonster(GtkWidget *mainWindow)
{
  t_winMonster	*winmonster;

  winmonster = my_xmalloc(sizeof(*winmonster));
  winmonster->mainWindow = mainWindow;
  init_winmonster(winmonster);
  g_signal_connect(G_OBJECT(winmonster->winButton[0]), "clicked",
		   G_CALLBACK(on_clicked_add_monster), winmonster);
  g_signal_connect(G_OBJECT(winmonster->winButton[1]), "clicked",
		   G_CALLBACK(on_clicked_next_monster), winmonster);
  gtk_widget_show_all(winmonster->mainWindow);
  gtk_main();
}
