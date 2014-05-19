/*
** main_example.c for LibClient_Example in /home/jobertomeu/Work/rush4/client
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Sat May 10 16:24:34 2014 Joris Bertomeu
** Last update Sat May 10 17:11:31 2014 Joris Bertomeu
*/

#include "libclient.h"

int	main()
{
  while (1)
    {
      send_str("Message test", "127.0.0.1", 33666);
      sleep(1);
    }
}
