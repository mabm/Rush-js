/*
** commands.c for RUSH-JS in /home/valer/JS
**
** Made by Valerian Polizzi
** Login   <valer@epitech.net>
**
** Started on  Sat May 10 01:28:23 2014 Valerian Polizzi
** Last update Sat May 10 19:45:36 2014 Laurent Fourrier
*/

#include <stdio.h>
#include "../../include/parsing.h"

char    *is_next(char *arg)
{
  printf("USER GOES TO %s", arg);
  return (arg);
}

char    *is_list_team(char *arg)
{
  printf("team = %s\n", arg);
  return (arg);
}

char    *is_attack(char *arg)
{
  printf("USER ATTACKS %s\n", arg);
  return (arg);
}

char    *is_attack_spe(char *arg)
{
  printf("USER ATTACKS SPE IS %s\n", arg);
  return (arg);
}

char    *is_who(char *arg)
{
  printf("USER IS %s\n", arg);
  return (arg);
}
