/*
** client.h for client in /home/merran_g/work/c_elem/epic_js_fantasy/gem_client
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Thu May 15 22:54:45 2014 Geoffrey Merran
** Last update Thu May 15 22:58:14 2014 Geoffrey Merran
*/

#ifndef CLIENT_
# define CLIENT_

typedef struct		s_champ
{
  char			*name;
  char			*type;
  int			*hp;
  int			*spe;
  int			*speed;
  int			*deg;
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
  t_monster	*mobs;
}		t_room;

#endif /* CLIENT_ */
