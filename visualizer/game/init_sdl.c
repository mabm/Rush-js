/*
** init_sdl.c for  in /home/charvo_a/rush/visualizer/game
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Sun May 11 22:36:59 2014 Nicolas Charvoz
** Last update Sun May 11 23:50:17 2014 Nicolas Charvoz
*/

#include "./hdr/game.h"
#include "test.h"

void	img_game(t_game *g)
{
  g->prev = NULL;
  g->prev = IMG_Load("/tmp/buttons/prev.png");
  g->next = NULL;
  g->next = IMG_Load("/tmp/buttons/next.png");
  g->map = NULL;
  g->map = IMG_Load("../res/maps/map_yayo.jpg");
}

void	img_player(t_player *p, t_champ *c)
{
  /* char	*skin; */

  /* skin = malloc(25 * sizeof(char)); */
  /* memset(skin, 0, 25); */
  /* sprintf(skin, "/tmp/skins/%s_male.png", c->class); */
  p->skin = NULL;
  //p->skin = IMG_Load(skin);
  p->skin = IMG_Load("../res/skins/yayo.png");
  p->hp = NULL;
  p->hp = IMG_Load("/tmp/sprites/blood_100.png");
}

void	img_monster(t_monster *m)
{
  m->skin = NULL;
  m->skin = IMG_Load("/tmp/sprites/monster4.png");
  m->hp = NULL;
  m->hp = IMG_Load("/tmp/sprites/blood_100.png");
}

void	img_load(t_champ *c, t_game *g, t_player *p, t_monster *m)
{
  img_game(g);
  img_player(p, c);
  img_monster(m);
}

void	init_sdl(t_champ *c, t_game *g, t_player *p, t_monster *m)
{
  img_load(c, g, p, m);
  img_blit(g, p, m);
}
