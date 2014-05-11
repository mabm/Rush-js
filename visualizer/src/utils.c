#include "../hdr/sdl.h"

int	center_text(char *str)
{
  int	i;
  int	a;

  i = 11;
  a = strlen(str);
  a = 0.5 * i * a;
  return (a * (-1));
}
