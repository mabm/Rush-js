/*
** editor.h for editor in /home/merran_g/work/c_elem/rush2
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Sat May 10 11:22:41 2014 Geoffrey Merran
** Last update Sun May 11 16:15:54 2014 Geoffrey Merran
*/

#ifndef EDITOR_
# define EDITOR_
# define MAGIC_NUMBER 123

/*
** Instructions defines
*/

/*
** Attributes
*/

# define NAME 0x01
# define ROOM_TO_WIN 0x02
# define ROOM_TO_START 0x03
# define TYPE 0x04
# define HP 0x05
# define SPEED 0x06
# define DEG 0x07
# define WEAPON 0x08
# define ARMOR 0x09
# define ADV 0x10
# define TAB_CONNEXION 0x11
# define TAB_MONSTER 0x12
# define ROOM 0x0F
# define SPE 0x20

/*
** Sections
*/

# define CHAMPION 0x0C
# define HEADER 0x0D
# define MONSTER 0x0E

/*
** Others
*/

# define SEP_SECTION 0x0A

/*
** Structures
*/

typedef struct		s_champ
{
  char			*name;
  char			*type;
  char			*hp;
  char			*spe;
  char			*speed;
  char			*deg;
  char			*weapon;
  char			*armor;
  struct s_champ	*next;
}			t_champ;

typedef struct		s_monster
{
  char			*type;
  char			*hp;
  char			*spe;
  char			*speed;
  char			*deg;
  char			*weapon;
  char			*armor;
  struct s_monster	*next;
}			t_monster;

typedef	struct	s_room
{
  char		*name;
  char		*adv;
  char		*access;
  char		*mobs;
  struct s_room	*next;
}		t_room;

typedef struct	s_header
{
  char		*name;
  t_room       	*end_room;
  t_room       	*start_room;
}		t_header;

typedef struct	s_game
{
  t_header	*header;
  t_champ	*champs;
  t_monster	*monsters;
  t_room	*rooms;
}		t_game;

#endif /* EDITOR_ */
