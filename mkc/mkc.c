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
  char include[] = "#include <unistd.h>\n#include <stdlib.h>\n#include <stdio.h>\n";
  char *name;
  int len;

  name = malloc((strlen(filename) + 2) * sizeof(*name));
  if (name == NULL)
    return (EXIT_FAILURE);
  fd = open(strcat(filename, ".c"), O_CREAT | O_EXCL | O_WRONLY, 00644);
  if (fd != -1)
    {      
      if (write_header(fd, filename) == EXIT_FAILURE)
	{
	  free(name);
	  return (EXIT_FAILURE);
	}
      free(name);
      if (write(fd, include, strlen(include)) < 0)
	return (EXIT_FAILURE);
      if (close(fd) < 0)
	return (EXIT_FAILURE);
      return (EXIT_SUCCESS);
    }
  free(name);
  return (EXIT_FAILURE);
}
