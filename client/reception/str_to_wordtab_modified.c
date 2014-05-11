/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/garcia_t/rpg
** 
** Made by garcia antoine
** Login   <garcia_t@epitech.net>
** 
** Started on  Sat May 10 13:56:08 2014 garcia antoine
** Last update Sat May 10 23:43:58 2014 
*/

#include <stdlib.h>
#include <string.h>

char    **my_str_to_wordtab1(char *str)
{
  int   i;
  int   j;
  int   k;
  char  **tab;

  i = 0;
  k = 0;
  tab = malloc(strlen(str) * sizeof(*tab));
  while (str[k])
    {
      j = 0;
      tab[i] = malloc(strlen(str) * sizeof(*tab[i]));
      while (str[k] != ' ' && str[k] != '\0')
        tab[i][j++] = str[k++];
      tab[i][j] = '\0';
      if (str[k] != '\0')
        k++;
      i++;
    }
  tab[i] = '\0';
  i = 0;
  return (tab);
}

char    **my_str_to_wordtab2(char *str)
{
  int   i;
  int   j;
  int   k;
  char  **tab;

  i = 0;
  k = 0;
  tab = malloc(strlen(str) * sizeof(*tab));
  while (str[k])
    {
      j = 0;
      tab[i] = malloc(strlen(str) * sizeof(*tab[i]));
      while (str[k] != ',' && str[k] != '\0')
        tab[i][j++] = str[k++];
      tab[i][j] = '\0';
      if (str[k] != '\0')
        k++;
      i++;
    }
  tab[i] = '\0';
  i = 0;
  return (tab);
}
