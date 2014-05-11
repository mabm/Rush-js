/*
** struct_client.h for rush in /home/fouhet_k/Perso/Rush_10_may/header/client
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Sat May 10 11:43:57 2014 Kevin Fouhety
** Last update Sat May 10 14:09:44 2014 Kevin Fouhety
*/

#ifndef STRUCT_CLIENT_H_
# define STRUCT_CLIENT_H_

typedef struct s_champ
{
  char			*name;
  char			*class;
  int			hp;
  int			spe;
  int			speed;
  int			dmg;
  char			*weapon;
  char			*armor;
}t_champ;

typedef struct s_list_champ
{
  char			*name;
  char			*class;
  int			hp;
  int			spe;
  int			speed;
  int			dmg;
  char			*weapon;
  char			*armor;
  struct s_list_champ	*next;
}t_list_champ;


#endif
