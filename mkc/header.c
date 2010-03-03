/*
** header.c for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Wed Mar  3 10:56:16 2010 francois1 ancel
** Last update Wed Mar  3 10:56:16 2010 francois1 ancel
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "../auteur.h"
#include "header.h"

int xfwrite(int fd, char *str)
{
  return (write(fd, str, strlen(str)));
}

int write_header(int fd, char *filename)
{
  time_t t;
  char *timefmt;

  t = time(NULL);
  timefmt = ctime(&t);
  timefmt[strlen(timefmt) - 1] = ' ';
  if (xfwrite(fd, "/*\n** ") < 0)
    return (EXIT_FAILURE);
  if (xfwrite(fd, filename) < 0)
    return (EXIT_FAILURE);
   if (xfwrite(fd, " for project in /u/all/") < 0)
    return (EXIT_FAILURE);
 if (xfwrite(fd, LOGIN) < 0)
    return (EXIT_FAILURE);
 if (xfwrite(fd, "/cu/travail/c/\n**\n** Made by ") < 0)
    return (EXIT_FAILURE);
 if (xfwrite(fd, NAME) < 0)
    return (EXIT_FAILURE);
 if (xfwrite(fd, "\n** Login   <") < 0)
    return (EXIT_FAILURE);
 if (xfwrite(fd, LOGIN) < 0)
    return (EXIT_FAILURE);
 if (xfwrite(fd, "@epitech.net>\n**\n** Started on  ") < 0)
    return (EXIT_FAILURE);
 if (xfwrite(fd, timefmt) < 0)
   return (EXIT_FAILURE);
 if (xfwrite(fd, NAME) < 0)
    return (EXIT_FAILURE);
 if (xfwrite(fd, "\n** Last update ") < 0)
    return (EXIT_FAILURE);
 if (xfwrite(fd, timefmt) < 0)
   return (EXIT_FAILURE);
 if (xfwrite(fd, NAME) < 0)
    return (EXIT_FAILURE);
 if (xfwrite(fd, "\n*/\n\n") < 0)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
