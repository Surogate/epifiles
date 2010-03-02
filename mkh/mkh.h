/*
** mkh.h for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Wed Feb 24 14:52:36 2010 francois1 ancel
** Last update Thu Feb 25 12:10:54 2010 francois1 ancel
*/

#ifndef MKH_H_INCLUDED
# define MKH_H_INCLUDED

int execfile(char *filename);
int xfwrite(int fd, char *str);
int write_header(int fd, char *filename);
int write_save(int fd, char *filename);

#endif
