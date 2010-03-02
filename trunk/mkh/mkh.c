/*
** main.c for nm in /u/all/ancel_a/cu/travail/c/nm-objdump
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Wed Feb 24 14:52:36 2010 francois1 ancel
** Last update Thu Feb 25 12:10:54 2010 francois1 ancel
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../auteur.h"

int main(int ac, char **av)
{
  int i;

  i = 1;
  while (i < ac)
    {
      if (execfile(av[i]) == EXIT_FAILURE)
	perror(av[i]);
      i++;
    }
  return (EXIT_SUCCESS);
}

int execfile(char *filename)
{   
  int fd;
  char *name;
  int len;

  filename[strlen(filename) - 1] = 'h';
  fd = open(filename, O_CREAT | O_EXCL | O_WRONLY, 00644);
  if (fd != -1)
    {      
      if (write_header(fd, filename) == EXIT_FAILURE)
	{
	  free(name);
	  return (EXIT_FAILURE);
	}
      free(name);
      if (write_save(fd, filename) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      if (close(fd) < 0)
	return (EXIT_FAILURE);
      return (EXIT_SUCCESS);
    }
  free(name);
  return (EXIT_FAILURE);
}

int xfwrite(int fd, char *str)
{
  return (write(fd, str, strlen(str)));
}

int write_save(int fd, char *filename)
{
  int i;

  for (i = 0; i < strlen(filename); i++)
    {
      if (filename[i] <= 'z' && filename[i] >= 'a')
	filename[i] = filename[i] - 32;
      if (filename[i] == '.')
	filename[i] = '_';
    }
  xfwrite(fd, "#ifndef ");
  xfwrite(fd, filename);
  xfwrite(fd, "_INCLUDED\n# define ");
  xfwrite(fd, filename);
  xfwrite(fd, "_INCLUDED\n\n\n\n#endif\n");
  return (EXIT_SUCCESS);
}

int write_header(int fd, char *filename)
{
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
 if (xfwrite(fd, "@epitech.net>\n**\n** Started on  Wed Feb 24 14:52:36 2010 ") < 0)
    return (EXIT_FAILURE);
 if (xfwrite(fd, NAME) < 0)
    return (EXIT_FAILURE);
 if (xfwrite(fd, "\n** Last update Thu Feb 25 12:10:54 2010 ") < 0)
    return (EXIT_FAILURE);
 if (xfwrite(fd, NAME) < 0)
    return (EXIT_FAILURE);
 if (xfwrite(fd, "\n*/\n\n") < 0)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
