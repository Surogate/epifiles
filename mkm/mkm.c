/*
** mkm.c for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Mon Mar  8 11:55:19 2010 francois1 ancel
** Last update Mon Mar  8 11:55:19 2010 francois1 ancel
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <regex.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include "mkm.h"
#include "make_header.h"

#define D_FILEA "NAME\t= "
#define D_FILEB "\nCC\t= gcc\nRM\t= rm -rf\nSRCS\t= "
#define D_CFLAGS "-W -Wall -Wextra -O3 -ansi"
#define D_FILEC "\n\nOBJS\t= $(SRCS:.c=.o)\nCFLAGS\t= -W -Wall -Wextra -O3 -ansi\nLDFLAGS\t= -lc\n\n$(NAME)\t: $(OBJS)\n\t$(CC) $(LDFLAGS) -o $(NAME) $(OBJS)\n\nall\t: $(NAME)\n\nclean\t:\n\t$(RM) $(OBJS)\n\nfclean\t: clean\n\t$(RM) $(NAME)\n\nre\t: fclean all"

int main(int ac, char **av)
{
  int result;

  if (ac > 1)
    result = exec(av[1]);
  else
    result = exec("prog");
  if (result != EXIT_SUCCESS)
    {
      if (result == EXIT_FAILURE)
	perror(av[0]);
      else if (result == -2)
	printf("regexcomp error");
    }
  return (EXIT_SUCCESS);
}

int exec(char *progname)
{
  int fdfile;
  int result;

  fdfile = open("Makefile", O_WRONLY | O_CREAT | O_EXCL, 00600);
  if (fdfile > 0)
    {
      result = write_file(fdfile, progname);
      close (fdfile);
      return (result);
    }
  return (EXIT_FAILURE);
}

int write_file(int fd, char *prog)
{
  int cc;

  if ((cc = write_header(fd, "Makefile")) != EXIT_SUCCESS)
    return (cc);
  if ((cc = write(fd, D_FILEA, strlen(D_FILEA))) <= 0)
    return (EXIT_FAILURE);
  if ((cc = write(fd, prog, strlen(prog))) <= 0)
     return (EXIT_FAILURE);
  if ((cc = write(fd, D_FILEB, strlen(D_FILEB))) <= 0)
    return (EXIT_FAILURE);
  if ((cc = copy_cfile(fd)) != EXIT_SUCCESS)
    return (cc);
  if ((cc = write(fd, D_FILEC, strlen(D_FILEC))) <= 0)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int copy_cfile(int fdfile)
{
  DIR *fd;
  int result;

  fd = opendir(".");
  if (fd != NULL)
    {
      result = listdir(fd, fdfile);
      closedir(fd);
      return (result);
    }
  return (EXIT_FAILURE);
}

int listdir(DIR *fd, int fdfile)
{
  regex_t preg;
  struct dirent *s_dir;
  const char *to_match = ".+\.c$";
  int err;
  int result;

  result = EXIT_SUCCESS;
  err = regcomp(&preg, to_match, REG_NOSUB | REG_EXTENDED);
  if (err == 0)
    {
      while ((s_dir = readdir(fd)) != NULL)
	{
	  if (regexec(&preg, s_dir->d_name, 0, NULL, 0) == 0)
	    {
	      if (err)
		if (write(fdfile, "\t\t\\\n\t", strlen("\t\t\\\n\t")) <= 0)
		  result = EXIT_FAILURE;
	      if (write(fdfile, s_dir->d_name, strlen(s_dir->d_name)) <= 0)
		result = EXIT_FAILURE;
	      if (!err)
		err = 1;
	    }
	}
      regfree(&preg);
      return (result);
    }
  return (-2);
}
