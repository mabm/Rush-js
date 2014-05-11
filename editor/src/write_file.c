/*
** write_file.c for write_file in /home/merran_g/work/c_elem/rush2
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Sat May 10 13:58:16 2014 Geoffrey Merran
** Last update Sat May 10 20:10:24 2014 Geoffrey Merran
*/

#include "parser.h"

void		write_string(int fd, char *str)
{
  char		size;

  size = strlen(str);
  write(fd, &size, 1);
  write(fd, str, size);
}

void	write_number(int fd, int nb)
{
  int	k;
  char	c;

  if (nb == -2147483648)
    write(fd, "-2147483648", 11);
  else
    {
      if (nb < 0)
	{
	  nb = nb * - 1;
	  write(fd, "-", 1);
	}
      k = nb;
      if (nb > 9)
	{
	  k = nb % 10;
	  write_number(fd, nb / 10);
	}
      c = (k + 48);
      write(fd, &c, 1);
    }
}

void	write_attribut(int fd, char att)
{
  write(fd, &att, 1);
}

void	write_header(int fd, t_header *header)
{
  write(fd, MAGIC_NUMBER, strlen(MAGIC_NUMBER));
  write_attribut(fd, HEADER);
  write_attribut(fd, NAME);
  write_string(fd, header->name);
  write_attribut(fd, ROOM_TO_WIN);
  write_string(fd, header->end_room->name);
  write_attribut(fd, ROOM_TO_START);
  write_string(fd, header->start_room->name);
  write_attribut(fd, SEP_SECTION);
}


void	write_champ(int fd, t_champ *champ)
{
  write_attribut(fd, CHAMPION);
  write_attribut(fd, NAME);
  write_string(fd, champ->name);
  write_attribut(fd, TYPE);
  write_string(fd, champ->type);
  write_attribut(fd, HP);
  write_string(fd, champ->hp);
  write_attribut(fd, SPE);
  write_string(fd, champ->spe);
  write_attribut(fd, SPEED);
  write_string(fd, champ->speed);
  write_attribut(fd, DEG);
  write_string(fd, champ->deg);
  write_attribut(fd, WEAPON);
  write_string(fd, champ->weapon);
  write_attribut(fd, ARMOR);
  write_string(fd, champ->armor);
  write_attribut(fd, SEP_SECTION);
}
