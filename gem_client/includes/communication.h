/*
** communication.h for communication in /home/merran_g/work/c_elem/epic_js_fantasy/gem_client
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Thu May 15 22:02:29 2014 Geoffrey Merran
** Last update Thu May 15 22:32:50 2014 Geoffrey Merran
*/

#ifndef COMMUNICATION_
# define COMMUNICATION_
# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libclient.h"
# include "reception.h"
# include "my.h"

extern t_libclient	*clt_com;

void   	*game_thread(void *data);
void 	init_communication(char *ip, int port);

#endif /* COMMUNICATION_ */
