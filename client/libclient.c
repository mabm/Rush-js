/*
** libclient.c for libclient in /home/jobertomeu/Work/ftp
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Sat May 10 15:21:44 2014 Joris Bertomeu
** Last update Sat May 10 16:25:58 2014 Joris Bertomeu
*/

#include "libclient.h"

void	print_error_lib(char *str)
{
  printf("Error : %s\n", str);
  exit(-1);
}

void	check_hostaddr(t_libclient *slib, char *ip)
{
  if ((long) slib->hostaddr != (long) -1)
    {
      bcopy(&(slib->hostaddr), &(slib->serversockaddr.sin_addr),
	    sizeof (slib->hostaddr));
      return ;
    }
  slib->serverhostent = gethostbyname(ip);
  if (slib->serverhostent == NULL)
    print_error_lib("Get host failed\n");
  bcopy(&(slib->serverhostent->h_addr), &(slib->serversockaddr.sin_addr),
	slib->serverhostent->h_length);
}

void	init_lib(t_libclient *slib, char *ip)
{
  slib->to_server_socket = -1;
  memset(&(slib->serversockaddr), 0, sizeof (slib->serversockaddr));
  slib->hostaddr = inet_addr(ip);
  check_hostaddr(slib, ip);
  slib->serversockaddr.sin_port = htons(21);
  slib->serversockaddr.sin_family = AF_INET;
  if ((slib->to_server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    print_error_lib("Socket creation failed\n");
  if(connect(slib->to_server_socket,
	      (struct sockaddr *) &slib->serversockaddr,
	      sizeof (slib->serversockaddr)) < 0 )
    print_error_lib("Connection request failed\n");
}

void	send_str(char *str, char *ip)
{
  t_libclient	*slib;

  slib = malloc(sizeof (*slib));
  init_lib(slib, ip);
  slib->flag = 1;

  write(slib->to_server_socket, str, strlen(str) - 1);
  read(slib->to_server_socket, slib->buffer, 4096);
  printf("Réponse : ");
  printf(slib->buffer);
  printf("\n");

  shutdown(slib->to_server_socket, 2);
  close(slib->to_server_socket);
  free(slib);
}
