/*
** commands.c for RUSH-JS in /home/valer/JS
**
** Made by Valerian Polizzi
** Login   <valer@epitech.net>
**
** Started on  Sat May 10 01:28:23 2014 Valerian Polizzi
** Last update Sat May 10 01:50:46 2014 Valerian Polizzi
*/

#include <stdio.h>
#include "parsing.h"

char    *is_next(char *arg)
{
  printf("USER GOES TO %s", arg);
}

char    *is_list_team(char *arg)
{
  printf("team = %s\n", arg);
}

char    *is_attack(char *arg)
{
  printf("USER ATTACKS %s\n", arg);
}

char    *is_attack_spe(char *arg)
{
  printf("USER ATTACKS SPE IS %s\n", arg);
}

char    *is_who(char *arg)
{
  printf("USER IS %s\n", arg);
}
