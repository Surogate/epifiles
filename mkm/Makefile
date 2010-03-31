##
## Makefile for project in /u/all/ancel_a/cu/travail/c/
##
## Made by francois1 ancel
## Login   <ancel_a@epitech.net>
##
## Started on  Wed Mar 31 13:55:23 2010 francois1 ancel
## Last update Wed Mar 31 13:55:23 2010 francois1 ancel
##

NAME	= mkm
CC	= gcc
RM	= rm -rf
SRCS	= make_header.c		\
	mkm.c

OBJS	= $(SRCS:.c=.o)
CFLAGS	= -W -Wall -Wextra -O3 -ansi
LDFLAGS	= -lc

$(NAME)	: $(OBJS)
	$(CC) $(LDFLAGS) -o $(NAME) $(OBJS)

all	: $(NAME)

clean	:
	$(RM) $(OBJS)

fclean	: clean
	$(RM) $(NAME)

re	: fclean all