/*
** parsing.h for RUSH-JS in /home/valer/JS
**
** Made by Valerian Polizzi
** Login   <valer@epitech.net>
**
** Started on  Sat May 10 01:38:36 2014 Valerian Polizzi
** Last update Sat May 10 01:51:14 2014 Valerian Polizzi
*/

#ifndef PARSING_H_
# define PARSING_H_

typedef  char*(*t_fonc_tab)(char*);

int	parse_cmd(char *cmd);
int	check_cmd(char *cmd_tab, char *cmd);
char	*get_opt(char *cmd);
char	*is_next(char *arg);
char	*is_list_team(char *arg);
char	*is_attack(char *arg);
char	*is_attack_spe(char *arg);
char	*is_who(char *arg);

#endif
