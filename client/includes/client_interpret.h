/*
** client_interpret.h for EPIC_JS_FANTASY in /home/cruvei_t/RUSH_PGM/client
** 
** Made by 
** Login   <cruvei_t@epitech.net>
** 
** Started on  Sun May 11 16:19:47 2014 
** Last update Sun May 11 16:23:57 2014 
*/

#ifndef CLIENT_INTERPRET_H_
#define CLIENT_INTERPRET_H_

char	*client_interpret_attack(char *buffer);
char	*client_interpret_next(char *buffer);
char	*client_interpret_spe(char *buffer);
char	*client_interpret_who(char *buffer);
char	*client_interpret_attack(char *buffer);
void	check_cmd_client(char *str, char *buff);
#endif
