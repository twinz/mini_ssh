##
## Makefile for son in /home/marten_a//zappy/work
## 
## Made by alexandre martens
## Login   <marten_a@epitech.net>
## 
## Started on  Wed Jun 26 14:08:09 2013 alexandre martens
## Last update Sun Jul 28 21:26:51 2013 alexandre martens
##

NAME		=	server

SRCS		=	server.c		\
			../common/cd_dir.c	\
			../common/cp_dir.c	\
			../common/ls_dir.c	\
			../common/mv_dir.c	\
			../common/nothing.c	\
			../common/pwd.c		\
			../common/rm_dir.c	\
			../common/xfunc.c	\
			../common/func_list.c	\
			../common/xfunc2.c


CC		=	gcc

RM		=	rm -f

OBJS		=	$(SRCS:.c=.o)

all		:	$(NAME)

$(NAME)		:	$(OBJS)
			$(CC) -o $(NAME) $(OBJS) -g

clean		:
			$(RM) $(OBJS)

fclean		:	clean
			$(RM) $(NAME)


re		:	fclean all