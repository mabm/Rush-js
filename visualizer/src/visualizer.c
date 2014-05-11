#include "../hdr/sdl.h"

int	visu_menu(t_list_champ **list)
{
  t_main	*m;
  t_champ	*champ;
  t_choice	*c;

  m = malloc(sizeof(*m));
  c = malloc(sizeof(*c));
  champ = malloc(6 * sizeof(*champ));
  init_SDL(m, champ, c, *list);
  return (0);
}
