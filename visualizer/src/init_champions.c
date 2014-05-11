#include "../hdr/sdl.h"
#include "../hdr/test.h"

void	init_perso(t_list_champ **list, t_champ *champ, int i, t_main *m, t_choice *c)
{
  char	*hp_str;
  char	*spe_str;
  SDL_Color color = {0, 0, 0};

  hp_str = int_to_str(test->hp);
  spe_str = int_to_str(test->spe);
  champ->name = NULL;
  champ->hp_numeric = NULL;
  champ->value_spe = NULL;
  champ->attack_value = NULL;
  champ->defense_value = NULL;
  c->pos_name.x = 670 + center_text(test->name);
  c->pos_name.y = 85;
  c->pos_hp_numeric.x = 655;
  c->pos_hp_numeric.y = 140;
  c->pos_value_spe.x = 655;
  c->pos_value_spe.y = 167;
  SDL_BlitSurface(c->background, NULL, m->ecran, &c->pos_background);
  if (i == 0)
    {
      c->pos_next.x = 685;
      c->pos_next.y = 540;
      c->pos_select.x = 345;
      c->pos_select.y = 540;
      SDL_BlitSurface(c->next, NULL, m->ecran, &c->pos_next);
    }
  else if (i == 5) /* NBR DE MONSTRES TOTAL ENVOYE PAR EDITEUR */
    {
      c->pos_prev.x = 0;
      c->pos_prev.y = 540;
      c->pos_select.x = 345;
      c->pos_select.y = 540;
      SDL_BlitSurface(c->prev, NULL, m->ecran, &c->pos_prev);
    }
  else
    {
      c->pos_prev.x = 0;
      c->pos_prev.y = 540;
      c->pos_select.x = 345;
      c->pos_select.y = 540;
      c->pos_next.x = 685;
      c->pos_next.y = 540;
    }
  champ->name = TTF_RenderText_Blended(c->info_police, (const char*)*list->name, color);
  srand(time(NULL));
  if (strcmp(*list->class, "Warrior") == 0)
    img_load_player_menu(champ, (rand() % 2));
  else if (strcmp(*list->class, "Wizard") == 0)
    img_load_player_menu(champ, (rand() % 2) + 2);
  else
    img_load_player_menu(champ, (rand() % 2) + 4);
  champ->hp_numeric = TTF_RenderText_Blended(c->info_police, (const char*)hp_str, color);
  champ->value_spe = TTF_RenderText_Blended(c->info_police, (const char*)spe_str, color);
  champ->attack_value = TTF_RenderText_Blended(c->info_police, (const char*)*list->weapon, color);
  champ->defense_value = TTF_RenderText_Blended(c->info_police, (const char*)*list->armor, color);
  SDL_BlitSurface(champ->perso, NULL, m->ecran, &champ->pos_perso);
  SDL_BlitSurface(champ->name, NULL, m->ecran, &c->pos_name);
  SDL_BlitSurface(champ->hp_numeric, NULL, m->ecran, &c->pos_hp_numeric);
  SDL_BlitSurface(champ->value_spe, NULL, m->ecran, &c->pos_value_spe);
  SDL_BlitSurface(champ->attack_value, NULL, m->ecran, &c->pos_attack);
  SDL_BlitSurface(champ->defense_value, NULL, m->ecran, &c->pos_defense);
  }

void	init_champions(t_main *m, t_champ *champ, t_choice *c, t_list_champ **list)
{
  int	i;

  i = 0;
  while (*list != NULL)
    {
      init_perso(*list, &champ[i], i,m, c);
      *list = *list->next;
    }
  choose_player(m, champ, c);
  SDL_Flip(m->ecran);
}
