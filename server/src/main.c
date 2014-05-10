/*
** main.c for  in /home/nicolas/Workspace/rush/rush_promo_js/server/src
** 
** Made by Nicolas Ades
** Login   <nicolas@epitech.net>
** 
** Started on  Sat May 10 13:24:57 2014 Nicolas Ades
** Last update Sat May 10 14:07:40 2014 Nicolas Ades
*/

int	main(int ac, char **av)
{
  if (ac != 2)
    {
      printf("USAGE: ./server [GAME FILE]\n");
      return (-1);
    }
  else
    pars_map(av[1]);
  return (0);
}
