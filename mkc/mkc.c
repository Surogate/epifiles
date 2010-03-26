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
#include "mkc.h"
#include "define.h"

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

int open_name(char *filename)
{
  int len = strlen(filename);

  if ((filename[len - 1] == 'c') && (filename[len - 2] == '.'))
    return (open(filename, O_CREAT | O_EXCL | O_WRONLY, 00644));
  else
    {
      char *name;

      name = malloc((len + 2) * sizeof(*name));
      if (name)
	{
	  int fd;

	  strcpy(name, filename);
	  strcat(name, ".c");
	  fd = open(name, O_CREAT | O_EXCL | O_WRONLY, 00644);
	  free(name);
	  return (fd);
	}
    }
  return (-1);
}

int execfile(char *filename)
{   
  int fd;
  char include[] = C_INCLUDE;
  char *name;
  int len;

  fd = open_name(filename);
  if (fd != -1)
    {      
      if (write_header(fd, filename) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      if (write(fd, include, strlen(include)) < 0)
	return (EXIT_FAILURE);
      if (close(fd) < 0)
	return (EXIT_FAILURE);
      return (EXIT_SUCCESS);
    }
  return (EXIT_FAILURE);
}
