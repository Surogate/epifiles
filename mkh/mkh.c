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

int open_name(char *filename)
{
  int len = strlen(filename);

  if (filename[len - 1] == 'c' && filename[len - 2] == '.')
    {
      filename[len - 1] = 'h';
      return (open(filename, O_CREAT | O_EXCL | O_WRONLY, 00644));
    }
  else
    {
      char *name = malloc((len + 2) * sizeof(*name));
      if (name)
	{
	  int fd;

	  strcpy(name, filename);
	  strcat(name, ".h");
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
  char *name;
  int len;

  fd = open_name(filename);
  if (fd != -1)
    {      
      if (write_header(fd, filename) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      if (write_save(fd, filename) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      if (close(fd) < 0)
	return (EXIT_FAILURE);
      return (EXIT_SUCCESS);
    }
  return (EXIT_FAILURE);
}

int open_cfile(char *filename)
{
  int len = strlen(filename);

  if (filename[len - 1] == 'c' && filename[len - 2] == '.')
    {
      if (access(filename, R_OK) == 0)
	return (open(filename, RD_ONLY));
    }
  else
    {
      char *name = malloc((len + 2) * sizeof(*name));
      if (name)
	{
	  int fd = -1;

	  strcpy(name, filename);
	  strcat(name, ".c");
	  if (access(name, R_OK) == 0)
	    fd = open(name, RD_ONLY);
	  free(name);
	  return (fd);
	}
    }
  return (-1);
}

int write_save(int fd, char *filename)
{
  int i;
  int fd;

  fd = open_cfile(filename);
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
  xfwrite(fd, "_INCLUDED\n\n");
  if (fd != -1)
    {
      write_proto(fd);
      close (fd);
    }
  xfwrite(fd, "\n\n#endif\n");
  return (EXIT_SUCCESS);
}