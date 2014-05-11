#ifndef SDL_H_
# define SDL_H_

# define _SVID_SOURCE
# define _BSD_SOURCE

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

typedef struct s_champ
{
  SDL_Surface   *hp_numeric;
  SDL_Surface   *perso;
  SDL_Rect      pos_perso;
  SDL_Surface   *value_spe;
  SDL_Surface   *name;
  SDL_Surface   *carac;
  SDL_Surface   *bio;
  SDL_Surface   *info;
  SDL_Surface   *attack_value;
  SDL_Surface   *defense_value;
}               t_champ;

typedef struct s_choice
{
  SDL_Surface   *prev;
  SDL_Surface   *next;
  SDL_Surface   *select;
  SDL_Rect	pos_value_spe;
  SDL_Rect	pos_hp_numeric;
  SDL_Rect      pos_select;
  SDL_Rect      pos_prev;
  SDL_Rect      pos_next;
  TTF_Font      *main_police;
  TTF_Font      *info_police;
  SDL_Surface   *background;
  SDL_Rect      pos_background;
  SDL_Rect      pos_name;
  SDL_Rect      pos_carac;
  SDL_Rect      pos_bio;
  SDL_Color     color;
  SDL_Rect	pos_attack;
  SDL_Rect	pos_defense;
}               t_choice;

typedef struct s_player
{
  SDL_Surface	*hp_bar;
  SDL_Rect	pos_hp_bar;
  SDL_Surface	*skin;
  SDL_Rect	pos_skin;
}		t_player;

typedef struct s_monster
{
  SDL_Surface	*hp_bar;
  SDL_Rect	pos_hp_bar;
  SDL_Surface	*skin;
  SDL_Rect	pos_skin;
}		t_monster;

typedef struct s_main
{
  SDL_Event     event;
  SDL_Surface   *cursor;
  SDL_Rect      pos_cursor;
  SDL_Surface   *ecran;
  SDL_Rect      *pos_ecran;
  int		continuer;
  int		i;
  SDL_Surface	*button;
  SDL_Surface	*text_button;
  SDL_Rect	pos_text_button;
  SDL_Rect	pos_button;
  TTF_Font	*police_button;
  SDL_Surface	*background;
  SDL_Rect	pos_background;
}               t_main;

/* utils.c */
int	center_text(char*);
/* init_SDL.c*/
void	first_init_SDL(t_main*, t_choice*);
void	init_SDL(t_main*, t_champ*, t_choice*);
/* img_load.c */
void	img_load_player_menu(t_champ*, int);
void	img_load_player(t_player*, int, int);
void	img_load_ingame(t_main*);
void	img_load_menu(t_main*, t_choice*);
/* convert_in_mem.c */
int	size_of_converted(int);
char	*int_to_str(int);
/* choose_player.c */
void	case_of_first(t_main*, int, int, t_champ*, t_choice*);
void	case_of_middle(t_main*, int, int, t_champ*, t_choice*);
void	case_of_last(t_main*, int, int, t_champ*, t_choice*);
void	mouse_button_up(t_main*, t_champ*, t_choice*);
void	choose_player(t_main*, t_champ*, t_choice*);
/* fade.c */
void	fade_out(t_main*, t_choice*);
void	fade_in(t_main*, t_choice*);
/* init_champions.c */
void	init_perso(t_list_champ**, t_champ*, int, t_main*, t_choice*);
void	init_test(t_test*);
void	init_champions(t_main*, t_champ*, t_choice*);
/* quit_game.c */
void	quit_game(t_main*);
void	key_pressed(t_main*, t_choice *c);

#endif /* !SDL_H */
