/*
** main.c<2> for main in /home/merran_g/work/c_elem/epic_js_fantasy/client
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Thu May 15 21:50:12 2014 Geoffrey Merran
** Last update Thu May 15 22:53:43 2014 Geoffrey Merran
*/

#include "communication.h"

t_libclient	*clt_com;

void	end_connexion(int signal)
{
  write(clt_com->to_server_socket, "bye", 4);
  shutdown(clt_com->to_server_socket, 2);
  close(clt_com->to_server_socket);
  free(clt_com);
  exit(0);
}

void		*game_thread(void *data)
{
  char		*str;

  str = reception_str();
  printf("%s\n", str);
  /* read(clt_com->to_server_socket, clt_com->buffer, 4096); */
  /* champ = client_take_a_champ(clt_com->buffer); */
  /* display_chosen_champ */
  /* write(clt_com->to_server_socket, champ.name, strlen(champ.name) + 1); */
  /* while (1) */
  /*   { */
      /* signal(SIGINT, &end_connexion); */
  /*     memset(buff, 0, 4096); */
  /*     write(0, "Request >> ", strlen("Request >> ")); */
  /*     read(0, buff, 4096); */
  /*     write(clt_com->to_server_socket, buff, strlen(buff)); */
  /*     memset(clt_com->buffer, 0, 4096); */
  /*     read(clt_com->to_server_socket, clt_com->buffer, 4096); */
  /*     printf("Reply > %s\n", clt_com->buffer); */
  /*   } */
  /* while (1) */
  /*   { */
  /*     signal(SIGINT, &end_connexion); */
  /*     if (my_turn(clt_com->buffer) == 0) */
  /* 	{ */
  /* 	  verifneeded = 1; */
  /* 	  i = read(0, str, 4096); */
  /* 	  str[i - 1] = '\0'; */
  /* 	  write(clt_com->to_server_socket, str, strlen(str)); */
  /* 	} */
  /*     if (verifneeded == 1) */
  /* 	{ */
  /* 	  verifneeded = 0; */
  /* 	  check_cmd_client(str, clt_com->buffer); */
  /* 	} */
  /*   } */
  return (NULL);
}

void		init_communication(char *ip, int port)
{
  pthread_t	thread;

  clt_com = my_xmalloc(sizeof(*clt_com));
  init_lib(clt_com, ip, port);
  signal(SIGINT, &end_connexion);
  clt_com->flag = 1;
  pthread_create(&thread, NULL, &game_thread, clt_com);
  pthread_join(thread, NULL);
}

int		main(int ac, char **argv)
{
  if (ac == 3)
    init_communication(argv[1], atoi(argv[2]));
  else
    printf("Usage : %s <IP_addr> <Port>\n", argv[0]);
  return (EXIT_SUCCESS);
}
