/*
** game.h for  in /home/charvo_a/rush/visualizer/game/hdr
**
** Made by Nicolas Charvoz
** Login   <charvo_a@epitech.net>
**
** Started on  Sun May 11 22:19:49 2014 Nicolas Charvoz
** Last update Sun May 11 23:18:46 2014 Nicolas Charvoz
*/

#ifndef GAME_H_
# define GAME_H_

# include <SDL/SDL.h>
# include <SDL/SDL_image.h>
# include <SDL/SDL_ttf.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <curses.h>
# include <stdio.h>
# include <term.h>
# include <time.h>

typedef	struct	s_player
{
  SDL_Surface	*skin;
  SDL_Surface	*hp;
  SDL_Rect	pos_skin;
  SDL_Rect	pos_hp;
}		t_player;

typedef	struct	s_monster
{
  SDL_Surface	*skin;
  SDL_Surface	*hp;
  SDL_Rect	pos_skin;
  SDL_Rect	pos_hp;
}		t_monster;

typedef	struct s_game
{
  SDL_Surface	*ecran;
  SDL_Surface	*prev;
  SDL_Surface	*next;
  SDL_Surface	*choix;
  SDL_Surface	*map;
  SDL_Rect	pos_prev;
  SDL_Rect	pos_choix;
  SDL_Rect	pos_next;
  SDL_Rect	pos_map;

}		t_game;

#endif
