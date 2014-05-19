/*
** main.c for  in /home/merran_g/work/c_piscine/mkdir
**
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
**
** Started on  Fri Oct  4 09:11:03 2013 Geoffrey Merran
** Last update Mon Dec  9 16:08:57 2013 Geoffrey Merran
*/

#include "my.h"

int	main(int argc, char **argv)
{
  my_putstr(argv[argc - 1]);
  my_putstr(" say Hello world\n");
  return (0);
}
