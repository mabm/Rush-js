/*
** parsing.h for RUSH-JS in /home/valer/JS
**
** Made by Valerian Polizzi
** Login   <valer@epitech.net>
**
** Started on  Sat May 10 01:38:36 2014 Valerian Polizzi
** Last update Sun May 11 17:33:10 2014 Joris Bertomeu
*/

#ifndef PARSING_H_
# define PARSING_H_

#include "libserver.h"
#include "world.h"

typedef  char*(*t_fonc_tab)(char*, t_libserver *);

int	parse_cmd(char *cmd, int id, t_libserver *libserver, t_world *world);
int	check_cmd(char *cmd_tab, char *cmd);
char	*get_opt(char *cmd);
char	*is_next(char *arg, t_libserver *libserver);
char	*bye(char *arg, t_libserver *libserver);
char	*is_list_team(char *arg, t_libserver *libserver);
char	*is_attack(char *arg, t_libserver *libserver);
char	*is_attack_spe(char *arg, t_libserver *libserver);
char	*is_who(char *arg, t_libserver *libserver);

#endif
