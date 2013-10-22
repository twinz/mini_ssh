##
## Makefile for son in /home/marten_a//zappy/work
## 
## Made by alexandre martens
## Login   <marten_a@epitech.net>
## 
## Started on  Wed Jun 26 14:08:09 2013 alexandre martens
## Last update Sun Jul 28 21:26:33 2013 alexandre martens
##

NAME		=	client

SRCS		=	client.c		\
			command.c		\
			../common/xfunc.c	\
			../common/xfunc2.c

CC		=	gcc

RM		=	rm -f

OBJS		=	$(SRCS:.c=.o)

all		:	$(NAME)

$(NAME)		:	$(OBJS)
			$(CC) -o $(NAME) $(OBJS)

clean		:
			$(RM) $(OBJS)

fclean		:	clean
			$(RM) $(NAME)


re		:	fclean all