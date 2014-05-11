/*
** struct_client.h for rush in /home/fouhet_k/Perso/Rush_10_may/header/client
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Sat May 10 11:43:57 2014 Kevin Fouhety
** Last update Sun May 11 10:52:43 2014 
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
  struct s_list_champ	*previous;
}t_list_champ;


#endif
