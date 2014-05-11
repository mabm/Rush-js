/*
** img_load.c for  in /home/charvo_a/sdl
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Sat May 10 15:15:38 2014 Nicolas Charvoz
** Last update Sun May 11 19:04:57 2014 Nicolas Charvoz
*/

#include "../hdr/sdl.h"

void	img_load_player_menu(t_champ *champ, int i)
{
  char *final;

  final = malloc(25 * sizeof(char));
  final = memset(final, 0, 25);
  sprintf(final, "/tmp/perso/perso%d.png", i);
  champ->pos_perso.x = 280;
  champ->pos_perso.y = 200;
  champ->perso = NULL;
  champ->perso = IMG_Load(final);
}

void	img_load_player(t_player *player, int i, int hp)
{
  char	*final;
  char	*hp_final;

  final = malloc(25 * sizeof(char));
  final = memset(final, 0, 25);
  hp_final = malloc(25 * sizeof(char));
  hp_final = memset(hp_final, 0, 25);
  sprintf(final, "/tmp/skins/%d.png", i);
  player->skin = NULL;
  player->skin = IMG_Load(final);
  sprintf(hp_final, "/tmp/sprites/blood_%d.png", hp);
  player->hp_bar = NULL;
  player->hp_bar = IMG_Load(hp_final);
}

void	img_load_ingame(t_main *m)
{
  m->background = NULL;
  m->background = IMG_Load("/tmp/res/back_game");
  m->pos_background.x = 0;
  m->pos_background.y = 0;
}

void	img_load_menu(t_main *m, t_choice *c)
{
  m->cursor = NULL;
  m->cursor = IMG_Load("/tmp/cursor/cursor.png");
  c->background = NULL;
  c->background = IMG_Load("/tmp/background/background_choice.jpg");
  c->pos_background.x = 0;
  c->pos_background.y = 0;
  c->prev = NULL;
  c->prev = IMG_Load("/tmp/buttons/prev.png");
  c->next = NULL;
  c->next = IMG_Load("/tmp/buttons/next.png");
  c->select = NULL;
  c->select = IMG_Load("/tmp/buttons/select.png");
  c->info_police = TTF_OpenFont("/tmp/fonts/info.ttf", 14);
  c->main_police = TTF_OpenFont("/tmp/fonts/main.ttf", 14);
  c->pos_bio.x = 580;
  c->pos_bio.y = 260;
  c->pos_attack.x = 640;
  c->pos_attack.y = 430;
  c->pos_defense.x = 640;
  c->pos_defense.y = 465;
}
