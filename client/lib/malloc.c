/*
** malloc.c for tsys in /home/fourri_l/Projects/lib/tsys
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Mon Dec  9 18:50:52 2013 Laurent Fourrier
** Last update Sat May 10 15:57:48 2014 
*/

#include <stdlib.h>
#include <stdio.h>
#include "tsys.h"

void	*ts_malloc(int size)
{
  void	*rtn;

  rtn = malloc(size);
  if (rtn == NULL)
    printf("Could not allocate memory\n");
  return (rtn);
}
