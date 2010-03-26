/*
** mkm.h for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Mon Mar  8 15:30:18 2010 francois1 ancel
** Last update Mon Mar  8 15:30:18 2010 francois1 ancel
*/

#ifndef MKM_H_INCLUDED
# define MKM_H_INCLUDED

int execname(char *progname, t_arg *arg);
int copy_cfile(int fdfile);
int listdir(DIR *fd, int fdfile);
int write_file(int fd, char *prog);
int find_force(int ac, char **av);

#endif
