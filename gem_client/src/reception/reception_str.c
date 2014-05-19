/*
** reception_str.c for reception_str in /home/merran_g/work/c_elem/epic_js_fantasy/gem_client
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Thu May 15 22:22:24 2014 Geoffrey Merran
** Last update Thu May 15 22:42:37 2014 Geoffrey Merran
*/

#include "reception.h"

char	*reception_str()
{
  char	*buff;

  buff = my_xmalloc(4096 * sizeof(char));
  memset(buff, 0, 4096);
  read(clt_com->to_server_socket, buff, 4096);
  return (buff);
}
