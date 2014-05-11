/*
** choose_player.c for  in /home/charvo_a/visualizer
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Sun May 11 16:09:06 2014 Nicolas Charvoz
** Last update Sun May 11 17:49:51 2014 Nicolas Charvoz
*/

#include "../hdr/sdl.h"

void	case_of_first(t_main *m, int x, int y, t_champ *champ, t_choice *c)
{
  SDL_BlitSurface(c->background, NULL, m->ecran, &c->pos_background);
  SDL_BlitSurface(champ[m->i].perso, NULL, m->ecran, &champ[m->i].pos_perso);
  SDL_BlitSurface(champ[m->i].name, NULL, m->ecran, &c->pos_name);
  SDL_BlitSurface(champ[m->i].hp_numeric, NULL, m->ecran, &c->pos_hp_numeric);
  SDL_BlitSurface(champ[m->i].value_spe, NULL, m->ecran, &c->pos_value_spe);
  SDL_BlitSurface(champ[m->i].attack_value, NULL, m->ecran, &c->pos_attack);
  SDL_BlitSurface(champ[m->i].defense_value, NULL, m->ecran, &c->pos_defense);
  SDL_BlitSurface(c->next, NULL, m->ecran, &c->pos_next);
  SDL_Flip(m->ecran);
  if ((x >= 690 && x <= 800) && (y >= 545 && y <= 595))
    {
      m->i++;
    }
 }

void	case_of_middle(t_main *m, int x, int y, t_champ *champ, t_choice *c)
{
  SDL_BlitSurface(c->background, NULL, m->ecran, &c->pos_background);
  SDL_BlitSurface(c->prev, NULL, m->ecran, &c->pos_prev);
  SDL_BlitSurface(c->next, NULL, m->ecran, &c->pos_next);
  SDL_BlitSurface(champ[m->i].perso, NULL, m->ecran, &champ[m->i].pos_perso);
  SDL_BlitSurface(champ[m->i].name, NULL, m->ecran, &c->pos_name);
  SDL_BlitSurface(champ[m->i].hp_numeric, NULL, m->ecran, &c->pos_hp_numeric);
  SDL_BlitSurface(champ[m->i].value_spe, NULL, m->ecran, &c->pos_value_spe);
  SDL_BlitSurface(champ[m->i].attack_value, NULL, m->ecran, &c->pos_attack);
  SDL_BlitSurface(champ[m->i].defense_value, NULL, m->ecran, &c->pos_defense);
  SDL_BlitSurface(c->next, NULL, m->ecran, &c->pos_next);
  SDL_Flip(m->ecran);
  if ((x >= 5 && x <= 115) && (y >= 545 && y <= 595))
    {
      m->i--;
    }
 else if ((x >= 690 && x <= 800) && (y >= 545 && y <= 595))
   {
     m->i++;
   }
}

void	case_of_last(t_main *m, int x, int y, t_champ *champ, t_choice *c)
{
  SDL_BlitSurface(c->background, NULL, m->ecran, &c->pos_background);
  SDL_BlitSurface(c->prev, NULL, m->ecran, &c->pos_prev);
  SDL_BlitSurface(champ[m->i].perso, NULL, m->ecran, &champ[m->i].pos_perso);
  SDL_BlitSurface(champ[m->i].name, NULL, m->ecran, &c->pos_name);
  SDL_BlitSurface(champ[m->i].hp_numeric, NULL, m->ecran, &c->pos_hp_numeric);
  SDL_BlitSurface(champ[m->i].value_spe, NULL, m->ecran, &c->pos_value_spe);
  SDL_BlitSurface(champ[m->i].attack_value, NULL, m->ecran, &c->pos_attack);
  SDL_BlitSurface(champ[m->i].defense_value, NULL, m->ecran, &c->pos_defense);
  SDL_BlitSurface(c->next, NULL, m->ecran, &c->pos_next);
  SDL_Flip(m->ecran);
  if ((x >= 5 && x <= 115) && (y >= 545 && y <= 595))
     {
       m->i--;
     }
}

void	mouse_button_up(t_main *m, t_champ *champ, t_choice *c)
{
  int	x;
  int	y;

  x = m->event.button.x;
  y = m->event.button.y;

  if (m->i == 0)
    case_of_first(m, x, y, champ, c);
  else if (m->i == 5) /*NBR DE PERSONNAGE POSSIBLE*/
    case_of_last(m, x, y, champ, c);
  else
    case_of_middle(m, x, y, champ, c);
  printf("m->i = %d\n", m->i);
}

void	choose_player(t_main *m, t_champ *champ, t_choice *c)
{
  m->continuer = 1;
  m->i = 0;
  SDL_BlitSurface(c->background, NULL, m->ecran, &c->pos_background);
  SDL_BlitSurface(champ[m->i].perso, NULL, m->ecran, &champ[m->i].pos_perso);
  SDL_BlitSurface(champ[m->i].name, NULL, m->ecran, &c->pos_name);
  SDL_BlitSurface(champ[m->i].hp_numeric, NULL, m->ecran, &c->pos_hp_numeric);
  SDL_BlitSurface(champ[m->i].value_spe, NULL, m->ecran, &c->pos_value_spe);
  SDL_BlitSurface(champ[m->i].attack_value, NULL, m->ecran, &c->pos_attack);
  SDL_BlitSurface(champ[m->i].defense_value, NULL, m->ecran, &c->pos_defense);
  SDL_BlitSurface(c->next, NULL, m->ecran, &c->pos_next);
  SDL_Flip(m->ecran);
  while (m->continuer == 1)
    {
      SDL_WaitEvent(&m->event);
      switch(m->event.type)
	{
	case SDL_QUIT:
	  quit_game(m);
	case SDL_KEYDOWN:
	  key_pressed(m, c);
	case SDL_MOUSEBUTTONUP:
	  mouse_button_up(m, champ, c);
	  break;
	}
    }
}
