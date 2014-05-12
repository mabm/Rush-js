/*
** commands.c for RUSH-JS in /home/valer/JS
**
** Made by Valerian Polizzi
** Login   <valer@epitech.net>
**
** Started on  Sat May 10 01:28:23 2014 Valerian Polizzi
** Last update Mon May 12 13:25:20 2014 Joris Bertomeu
*/

#include <stdio.h>
#include "room.h"
#include "utils.h"
#include "parsing.h"
#include "champion.h"
#include "monster.h"

t_champion	*get_champion_from_id(int id, t_libserver *libserver)
{
  int	i;

  i = 0;
  while (i < 7)
    {
      if (libserver->clients[i].idsock == id)
	return (libserver->clients[i].champion);
      i++;
    }
}

int	get_fd_from_id(int id, t_libserver *libserver)
{
  int	i;

  i = 0;
  while (i < 7)
    {
      if (libserver->clients[i].idsock == id)
	return (libserver->clients[i].fd);
      i++;
    }
}

char		*is_next(char *arg, t_libserver *libserver)
{
  t_champion	*champ;
  t_room	*room;

  int		room_cmp(void *vfirst, void *vsecond)
  {
    char	*first;
    t_room	*second;

    first = vfirst;
    second = vsecond;
    return (strcmp(first, second->name));
  }
  room = tl_get_elem(libserver->world->rooms, arg, &room_cmp);
  if (room)
    {
      champ = get_champion_from_id(libserver->current_id_fd, libserver);
      room = tl_get_elem(libserver->world->rooms, champ->room, &room_cmp);
      if (room->monster[0])
	{
	  /* SEND ERROR MONSTERS ALIVE */
	}
      else
	{
	  champ->room = arg;
	  /* SEND OK */
	}
    }
  else
    {
      /* SEND ERROR NO ROOM */
    }
  return (arg);
}

char	*get_name_by_id(t_libserver *libserver, int flag)
{
  int	i;
  char	*addr_client;

  addr_client = malloc(20 * sizeof(*addr_client));
  memset(addr_client, 0, 20);
  i = 0;
  while (i < 7)
    {
      if (libserver->clients[i].idsock == libserver->current_id_fd)
	{
	  inet_ntop(AF_INET, &(libserver->clients[i].id),
		    addr_client, INET_ADDRSTRLEN);
	  if (flag == 1)
	    libserver->clients[i].active = 0;
	  return (addr_client);
	}
      i++;
    }
}

char		*bye(char *arg, t_libserver *libserver)
{
  printf("%s Quitte le server\n", get_name_by_id(libserver, 1));
  return (arg);
}

char		*is_list_team(char *arg, t_libserver *libserver)
{
  int	i;
  char	*classe;
  char	*trame;

  trame = malloc(4096 * sizeof(*trame));
  classe = malloc(128 * sizeof(*classe));
  memset(trame, 0, 4096);
  strcpy(trame, "OK NB:Value");
  i = 0;
  while (i < 7)
    {
      if (libserver->clients[i].active == 1)
	{
	  memset(classe, 0, 127);
	  if (libserver->clients[i].champion->class == 0)
	    strcpy(classe, "WARRIOR");
	  else if (libserver->clients[i].champion->class == 1)
	    strcpy(classe, "WIZARD");
	  else
	    strcpy(classe, "TEMPLAR");
	  sprintf(trame, "%s CHAMP:NAME=%s,TYPE=%s,HP=%d,SPE=%d,SPEED=%d,\
DEG=%d,WEAPON=%s,ARMOR=%s", trame, libserver->clients[i].champion->name, classe,
		  libserver->clients[i].champion->hp,
		  libserver->clients[i].champion->mana,
		  libserver->clients[i].champion->speed,
		  libserver->clients[i].champion->damage,
		  libserver->clients[i].champion->weapon,
		  libserver->clients[i].champion->armor);
	}
      i++;
    }
  printf("Sent trame : %s\n", trame);
  write(get_fd_from_id(libserver->current_id_fd, libserver), trame, strlen(trame));
  return (arg);
}

t_monsters	*get_monster(t_libserver *libserver, t_monsters *tmp,
			     char *arg, int *flag)
{
  t_list	*cur;

  cur = libserver->world->monsters;
  *flag = 0;
  while (cur)
    {
      tmp = (t_monsters *) cur->data;
      if (tmp->id == atoi(arg))
	*flag = 1;
      cur = cur->next;
    }
  return (tmp);
}

char	*generate_trame_monster(t_monsters *tmp)
{
  char	*trame;

  trame = malloc(4096 * sizeof(*trame));
  memset(trame, 0, 4096);
  sprintf(trame, "OK NB:Value MONSTER:ID=%d,TYPE=%s,HP=%d", tmp->id,
	  tmp->type, tmp->hp);
  return (trame);
}

char	*generate_trame_monster_err()
{
  char	*trame;

  trame = malloc(4096 * sizeof(*trame));
  memset(trame, 0, 4096);
  sprintf(trame, "ERR NB:Value MSG:\"Monster does not exist here\"");
  return (trame);
}

char		*is_attack(char *arg, t_libserver *libserver)
{
  t_monsters	*tmp;
  t_champion	*champ;
  int		flag;
  char		*trame;

  tmp = get_monster(libserver, tmp, arg, &flag);
  champ = get_champion_from_id(libserver->current_id_fd, libserver);
  if (flag)
    {
      printf("Attacked monster : %s\n", tmp->type);
      printf("Monster hp before : %d\n", tmp->hp);
      tmp->hp -= champ->damage;
      printf("Monster hp after : %d\n", tmp->hp);
      trame = generate_trame_monster(tmp);
    }
  else
    trame = generate_trame_monster_err();
  write(get_fd_from_id(libserver->current_id_fd, libserver), trame,
	strlen(trame));
  return (arg);
}

void	modify_spe(t_champion *champ, t_monsters *monster)
{
  if (champ->class == WARRIOR)
    {
      champ->damage *= 2;
      champ->mana /= 2;
    }
  else if (champ->class == WIZARD)
    {
      monster->hp -= (champ->damage * 6);
      champ->mana = 0;
    }
  else
    {
      champ->hp += (10 * champ->damage);
      champ->speed -= 10;
      champ->damage -= 10;
      champ->mana = 0;
    }
}

char		*is_attack_spe(char *arg, t_libserver *libserver)
{
  t_champion	*champ;
  t_monsters	*monster;
  int		flag;
  char		*trame;

  champ = get_champion_from_id(libserver->current_id_fd, libserver);
  monster = get_monster(libserver, monster, arg, &flag);
  if (monster)
    {
      if (champ->mana > 0)
	modify_spe(champ, monster);
      printf("Attacked spé monster : %s\n", monster->type);
      trame = generate_trame_monster(monster);
    }
  else
    trame = generate_trame_monster_err();
  write(get_fd_from_id(libserver->current_id_fd, libserver), trame,
	strlen(trame));
  return (arg);
}

char		*is_who(char *arg, t_libserver *libserver)
{
  t_champion	*champ;

  int		who_champ_cmp(void *vfirst, void *vsecond)
  {
    char	*first;
    t_champion	*second;

    first = vfirst;
    second = vsecond;
    return (strcmp(first, second->room));
  }
  write(get_fd_from_id(libserver->current_id_fd, libserver), "who", 4);
  /* champ = get_champion_from_id(libserver->current_id_fd, libserver); */
  /* champ = tl_get_elem(libserver->world->champions, champ->room, &who_champ_cmp); */
  /* SEND OK */
  /* SEND CHAMP NAME */
  return (arg);
}
