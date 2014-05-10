/*
** write_file2.c for write_file in /home/merran_g/work/c_elem/rush2
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Sat May 10 14:51:42 2014 Geoffrey Merran
** Last update Sat May 10 20:10:54 2014 Geoffrey Merran
*/

#include "parser.h"

void		write_room(int fd, t_room *room)
{
  write_attribut(fd, ROOM);
  write_attribut(fd, NAME);
  write_string(fd, room->name);
  write_attribut(fd, ADV);
  write_string(fd, room->adv);
  write_attribut(fd, TAB_CONNEXION);
  write_string(fd, room->access);
  write_attribut(fd, TAB_MONSTER);
  write_string(fd, room->mobs);
  write_attribut(fd, SEP_SECTION);
}

void		write_monster(int fd, t_monster *monster)
{
  write_attribut(fd, MONSTER);
  write_attribut(fd, TYPE);
  write_string(fd, monster->type);
  write_attribut(fd, HP);
  write_string(fd, monster->hp);
  write_attribut(fd, SPE);
  write_string(fd, monster->spe);
  write_attribut(fd, SPEED);
  write_string(fd, monster->speed);
  write_attribut(fd, DEG);
  write_string(fd, monster->deg);
  write_attribut(fd, WEAPON);
  write_string(fd, monster->weapon);
  write_attribut(fd, ARMOR);
  write_string(fd, monster->armor);
  write_attribut(fd, SEP_SECTION);
}

