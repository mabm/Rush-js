/*
** addlist.c for addlist in /home/merran_g/work/c_elem/epic_js_fantasy/editor/src
** 
** Made by Geoffrey Merran
** Login   <merran_g@epitech.net>
** 
** Started on  Sun May 11 15:37:19 2014 Geoffrey Merran
** Last update Sun May 11 19:47:04 2014 Jeremy Mediavilla
*/

#define _BSD_SOURCE
#include "parser.h"

void		add_champion(t_winChampion *data, t_champ **champs)
{
  t_champ	*new;

  new = my_xmalloc(sizeof(*new));
  new->name = strdup((char *) gtk_entry_get_text(
						 GTK_ENTRY(data->attEntry[0])));
  new->type = strdup((char *) gtk_combo_box_get_active_text(
							    GTK_COMBO_BOX(data->combo_box)));
  new->hp = strdup((char *) gtk_entry_get_text(GTK_ENTRY(data->attEntry[2])));
  new->spe = strdup((char *) gtk_entry_get_text(GTK_ENTRY(data->attEntry[3])));
  new->speed = strdup((char *) gtk_entry_get_text(
						  GTK_ENTRY(data->attEntry[4])));
  new->deg = strdup((char *) gtk_entry_get_text(
						GTK_ENTRY(data->attEntry[5])));
  new->weapon = strdup((char *) gtk_entry_get_text(
						   GTK_ENTRY(data->attEntry[6])));
  new->armor = strdup((char *) gtk_entry_get_text(
						  GTK_ENTRY(data->attEntry[7])));
  new->next = *champs;
  *champs = new;
  printf("===============\n");
  printf("-Adding New Champion-\nName :[%s] Type : [%s]\n",
	 new->name, new->type);
  printf("Stats - Hp: %s, Spe: %s, Speed: %s\n",
	 new->hp, new->spe, new->speed);
  printf("Weapon : [%s] - Armor : [%s]\n", new->weapon, new->armor);
  printf("===============\n");
}

void		add_monster(t_winMonster *data, t_monster **monsters)
{
  t_monster	*new;

  new = my_xmalloc(sizeof(*new));
  new->type = strdup((char *) gtk_entry_get_text(
						 GTK_ENTRY(data->attEntry[0])));
  new->hp = strdup((char *) gtk_entry_get_text(GTK_ENTRY(data->attEntry[1])));
  new->spe = strdup((char *) gtk_entry_get_text(GTK_ENTRY(data->attEntry[2])));
  new->speed = strdup((char *) gtk_entry_get_text(
						  GTK_ENTRY(data->attEntry[3])));
  new->deg = strdup((char *) gtk_entry_get_text(
						GTK_ENTRY(data->attEntry[4])));
  new->weapon = strdup((char *) gtk_entry_get_text(
						   GTK_ENTRY(data->attEntry[5])));
  new->armor = strdup((char *) gtk_entry_get_text(
						  GTK_ENTRY(data->attEntry[6])));
  new->next = *monsters;
  *monsters = new;
  printf("===============\n");
  printf("-Adding New Monster-\nType : [%s]\n", new->type);
  printf("Stats - Hp: %s, Spe: %s, Speed: %s\n",
	 new->hp, new->spe, new->speed);
  printf("Weapon : [%s] - Armor : [%s]\n=========\n", new->weapon, new->armor);
}

void		add_room(t_winRoom *data, t_room **rooms)
{
  t_room	*new;

  new = my_xmalloc(sizeof(*new));
  new->name = strdup((char *) gtk_entry_get_text(
						 GTK_ENTRY(data->attEntry[0])));
  new->adv = strdup((char *) gtk_entry_get_text(
						GTK_ENTRY(data->attEntry[1])));
  new->access = strdup((char *) gtk_entry_get_text(
						   GTK_ENTRY(data->attEntry[2])));
  new->mobs = strdup((char *) gtk_entry_get_text(
						 GTK_ENTRY(data->attEntry[3])));
  new->next = *rooms;
  *rooms = new;
  if (GTK_TOGGLE_BUTTON(G_OBJECT(data->checkButton[0]))->active)
    game->header->start_room = new;
  if (GTK_TOGGLE_BUTTON(G_OBJECT(data->checkButton[1]))->active)
    {
      printf("End room\n");
      game->header->end_room = new;
    }
  printf("===============\n");
  printf("-Adding New Room-\nName : [%s]\n", new->name);
  printf("Adv : [%s]\n", new->adv);
  printf("Connexions : [%s]\nMonsters : [%s]\n", new->access, new->mobs);
  printf("===============\n");
}
