/*
** commands.c for RUSH-JS in /home/valer/JS
**
** Made by Valerian Polizzi
** Login   <valer@epitech.net>
**
** Started on  Sat May 10 01:28:23 2014 Valerian Polizzi
** Last update Sun May 11 19:24:31 2014 Laurent Fourrier
*/

#include <stdio.h>
#include "room.h"
#include "utils.h"
#include "parsing.h"
#include "champion.h"

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
      champ = get_champion_from_id(libserver->id_client);
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

char		*bye(char *arg, t_libserver *libserver)
{
  printf("%s Quitte le server\n");
  return (arg);
}

char		*is_list_team(char *arg, t_libserver *libserver)
{
  void		listteam_it(void *data)
  {
    t_champion	*champ;

    /* SEND CHAMPION INFORMATION TO CLIENT HERE */
  }
  /* SEND OK:NB Value HERE */
  tl_iterate(libserver->world->champions, &listteam_it);
  return (arg);
}

char		*is_attack(char *arg, t_libserver *libserver)
{
  t_champion	*champ;
  t_monsters	*monster;

  int		atk_monster_cmp(void *vfirst, void *vsecond)
  {
    char	*first;
    t_monsters	*second;

    first = vfirst;
    second = vsecond;
    return (strcmp(first, second->type));
  }
  champ = get_champion_from_id(libserver->id_client);
  monster = tl_get_elem(libserver->world->monsters, arg, &atk_monster_cmp);
  if (monster)
    {
      monster->hp -= champ->damage;
      /* SEND OK HERE */
    }
  else
    {
      /* SEND ERROR MONSTER DOESNT EXISTS */
    }
  return (arg);
}

char		*is_attack_spe(char *arg, t_libserver *libserver)
{
  t_champion	*champ;
  t_monsters	*monster;

  int		spe_monster_cmp(void *vfirst, void *vsecond)
  {
    char	*first;
    t_monsters	*second;

    first = vfirst;
    second = vsecond;
    return (strcmp(first, second->type));
  }
  champ = get_champion_from_id(libserver->id_client);
  monster = tl_get_elem(libserver->world->monsters, arg, &spe_monster_cmp);
  if (monster)
    {
      if (champ->mana > 0)
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
      /* SEND OK */
    }
  else
    {
      /* SEND ERROR MONSTER DOESNT EXISTS */
    }
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
  champ = get_champion_from_id(libserver->id_client);
  champ = tl_get_elem(libserver->world->champions, champ->room, &who_champ_cmp);
  /* SEND OK */
  /* SEND CHAMP NAME */
  return (arg);
}
