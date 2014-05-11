/*
** commands.c for RUSH-JS in /home/valer/JS
**
** Made by Valerian Polizzi
** Login   <valer@epitech.net>
**
** Started on  Sat May 10 01:28:23 2014 Valerian Polizzi
** Last update Sun May 11 18:19:54 2014 Joris Bertomeu
*/

#include <stdio.h>
#include "../../include/parsing.h"

char    *is_next(char *arg, t_libserver *libserver)
{
  printf("USER GOES TO %s", arg);
  return (arg);
}

char    *bye(char *arg, t_libserver *libserver)
{
  printf("%s Quitte le server\n");
  return (arg);
}

char    *is_list_team(char *arg, t_libserver *libserver)
{
  printf("team = %s\n", arg);
  return (arg);
}

char    *is_attack(char *arg, t_libserver *libserver)
{
  printf("USER ATTACKS %s\n", arg);
  return (arg);
}

char    *is_attack_spe(char *arg, t_libserver *libserver)
{
  printf("USER ATTACKS SPE IS %s\n", arg);
  return (arg);
}

char    *is_who(char *arg, t_libserver *libserver)
{
  printf("USER IS %s\n", arg);
  return (arg);
}
