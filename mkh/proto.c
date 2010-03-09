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
#include <sys/types.h>
#include <sys/stat.h>

int write_proto(int fd)
{
  char *file;
  struct stat *s_stat;
  int err;
  regex_t preg;
  const char *match_exp = ".+ .+\(.+\)[:space:]";

  fstat(fd, s_stat);
  file = (char *)mmap(0, s_stat->st_size, PROT_READ, MAP_PRIVATE, fd, 0);
  if (file)
    {
      if ((err = regcomp (&preg, match_exp, REG_EXTENDED)) == 0)
	{
	  char *line;
	  while (line = gets(file))
	    {
	      if (regexec(&preg, match_exp, 0, NULL, 0) == 0)
		{
		  write(1, 
		}
	    }
	  regfree(&preg);
	}
      munmap(file);
    }
  return (EXIT_SUCCESS);
}
