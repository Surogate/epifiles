##
## Makefile for mko in /u/all/ancel_a/cu/travail/c/
## 
## Made by francois1 ancel
## Login   <ancel_a@epitech.net>
## 
## Started on  Wed Feb 24 14:54:39 2010 francois1 ancel
## Last update Thu Feb 25 12:10:14 2010 francois1 ancel
##

NAME	= mkh
CC	= gcc
RM	= rm -rf
SRCS	= mkh.c	\
	header.c

OBJS	= $(SRCS:.c=.o)
CFLAGS	= -O3
LDFLAGS	= -lc

$(NAME) : $(OBJS)
	$(CC) $(LDFLAGS) -o $(NAME) $(OBJS)

all	: $(NAME)

clean	:
	$(RM) $(OBJS)

fclean	: clean
	$(RM) $(NAME)

re	: fclean all