/*
** proto for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Mon Mar  8 23:04:57 2010 francois1 ancel
** Last update Mon Mar  8 23:04:57 2010 francois1 ancel
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <regex.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>

#define _MEOF -2

char *gnl(char *str)
{
  static int count;
  char *line;
  int len;
  int o;

  len = 0;
  if (count)
    {
      while (str[count] == '\n')
	count++;
    }
  while (str[count + len] && str[count + len] != '\n')
    len++;
  if (len)
    {
      line = malloc((len) * sizeof(*line));
      if (line)
	{
	  for (o = 0; o < len; o++)
	    line[o] = str[count + o];
	  line[len] = '\0';
	  count += len;
	  return (line);
	}
      return (NULL);
    }
  return ((char *)_MEOF);
}

int match_proto(char *str)
{
  const char *match_exp = ".+ .+\(.+\)";
  regex_t preg;
  int err;

  if ((err = regcomp (&preg, match_exp, REG_EXTENDED)) == 0)
    {
      char *line;
     
      while ((line = gnl(str)) != (char *)_MEOF)
	{
	  if (line)
	    {
	      if (regexec(&preg, line, 0, NULL, 0) == 0)
		printf("%s\n", line);
	      free(line);
	    }
	}
      regfree(&preg);
      return (EXIT_SUCCESS);
    }
  return (EXIT_FAILURE);
}

int write_proto(int fd)
{
  void *file;
  struct stat s_stat;
  int err;

  err = fstat(fd, &s_stat);
  if (err == -1)
    {
      perror("stat impossible");
      return (EXIT_FAILURE);
    }
  if (s_stat.st_size == 0)
    {
      printf("le fichier .c est vide");
      return (EXIT_SUCCESS);
    }
  file = mmap(NULL, (size_t)s_stat.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
  if (file != (char *)MAP_FAILED)
    {
      char *str = (char *)file;
      match_proto(str);
      munmap(file, s_stat.st_size);
      return (EXIT_SUCCESS);
    }
  perror("mmap fail");
  return (EXIT_FAILURE);
}
