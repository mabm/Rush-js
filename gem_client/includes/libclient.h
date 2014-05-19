/*
** libclient.h for libClient in /home/jobertomeu/Work/rush4/client
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Sat May 10 15:44:42 2014 Joris Bertomeu
** Last update Thu May 15 22:41:47 2014 Geoffrey Merran
*/

#ifndef LIBCLIENT_H_
# define LIBCLIENT_H_
# define h_addr h_addr_list[0];
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <strings.h>
# include <unistd.h>
# include <errno.h>
# include <signal.h>
# include <netdb.h>
# include <netinet/in.h>
# include <sys/socket.h>
# include <arpa/inet.h>


typedef struct	       	s_libclient
{
  struct sockaddr_in	serversockaddr;
  struct hostent	*serverhostent;
  long			hostaddr;
  long			status;
  char			buffer[4096];
  int			to_server_socket;
  int			flag;
}			t_libclient;

void	send_str(char *str, char *ip, int port);
void	init_lib(t_libclient *slib, char *ip, int port);
void	check_hostaddr(t_libclient *slib, char *ip);
void	print_error_lib(char *str);

#endif /* LIBCLIENT_H_ */
