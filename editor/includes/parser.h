/*
** parser.h for parser in /home/merran_g/work/c_elem/rush2
**
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
**
** Started on  Sat May 10 12:14:15 2014 Geoffrey Merran
** Last update Sun May 11 20:09:25 2014 Jeremy Mediavilla
*/

#ifndef PARSER_
# define PARSER_
# define EDITOR_USAGE "Usage : ./epic_editor\n"
# define WIN_X 800
# define WIN_Y 600
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <gtk/gtk.h>
# include "editor.h"
# include "my.h"

/*
** Graphic Editor & Windows
*/

extern t_game	*game;

typedef struct	s_winMap
{
  GtkWidget	*mainWindow;
  GtkWidget	*labelWin[2];
  GtkWidget	*tableWin;
  GtkWidget	*winButton[4];
  GtkWidget	*mapEntry;
}		t_winMap;

typedef struct	s_winMonster
{
  GtkWidget	*mainWindow;
  GtkWidget	*labelWin[8];
  GtkWidget	*tableWin;
  GtkWidget	*winButton[2];
  GtkWidget	*attEntry[7];
}		t_winMonster;

typedef struct	s_winChampion
{
  GtkWidget	*combo_box;
  GtkWidget	*mainWindow;
  GtkWidget	*labelWin[9];
  GtkWidget	*tableWin;
  GtkWidget	*winButton[2];
  GtkWidget	*attEntry[8];
}		t_winChampion;

typedef struct	s_winRoom
{
  GtkWidget	*mainWindow;
  GtkWidget	*checkButton[2];
  GtkWidget	*labelWin[5];
  GtkWidget	*tableWin;
  GtkWidget	*winButton[2];
  GtkWidget	*attEntry[4];
}		t_winRoom;

void	launch_editor();
void   	init_window(GtkWidget **mainWindow);

/*
** WinMenu
*/

void	create_window(GtkWidget *mainWindow);
void   	init_winmap(t_winMap *winmap);
void   	init_button_winmap(t_winMap *winmap);
void   	on_clicked_createbutton(GtkWidget *button, t_winMap *data);
void   	on_clicked_nextbutton(GtkWidget *button, t_winMap *data);


/*
** WinMonster
*/

void	create_winmonster(GtkWidget *mainWindow);
void   	init_winmonster(t_winMonster *winmonster);
void   	create_att_monster(t_winMonster *winmonster);
void   	pos_att_monster(t_winMonster *winmonster);
void   	on_clicked_add_monster(GtkWidget *addButton, t_winMonster *data);
void   	on_clicked_next_monster(GtkWidget *prevButton, t_winMonster *data);


/*
** WinRoom
*/

void   	create_winroom(GtkWidget *mainWindow);
void 	init_winroom(t_winRoom *winroom);
void   	create_att_room(t_winRoom *winroom);
void   	pos_att_room(t_winRoom *winroom);
void   	on_clicked_add_room(GtkWidget *addButton, t_winRoom *data);
void   	on_clicked_previous_room(GtkWidget *prevButton, t_winRoom *data);

/*
** WinChampion
*/

void	create_winchampion(GtkWidget *mainWindow);
void   	init_winchampion(t_winChampion *winchampion);
void   	create_att_champion(t_winChampion *winchampion);
void   	pos_att_champion(t_winChampion *winchampion);
void   	on_clicked_add_champ(GtkWidget *addButton, t_winChampion *data);
void   	on_clicked_next_champ(GtkWidget *prevButton, t_winChampion *data);

/*
** Add To lists
*/

void   	add_champion(t_winChampion *data, t_champ **champs);
void   	add_monster(t_winMonster *data, t_monster **monsters);
void   	add_room(t_winRoom *data, t_room **rooms);

/*
** Write in file
*/

void   	create_map();
int	create_file(char *name);
void   	put_champs(int fd);
void	write_header(int fd, t_header *header);
void	write_champ(int fd, t_champ *champ);
void	write_string(int fd, char *str);
void	write_number(int fd, int nb);
void	write_room(int fd, t_room *room);
void	write_monster(int fd, t_monster *monster);
void	write_attribut(int fd, char att);

/*
** Xfunction
*/

int	xopen(const char *pathname, int flags, mode_t mode);
void	my_error(char *error);

/* check error functions */
char	*check_champ_errors(t_winChampion *);
char	*check_monst_errors(t_winMonster *);
char	*check_room_error(t_winRoom *);

#endif /* PARSER_ */
