/*
** message.h for message in /home/marten_a//fluzifix/common
** 
** Made by alexandre martens
** Login   <marten_a@epitech.net>
** 
** Started on  Sun Jul 28 18:56:19 2013 alexandre martens
** Last update Mon Jul 29 21:46:51 2013 alexandre martens
*/

#ifndef			MESSAGE_H_
# define		MESSAGE_H_

#define			NB_READ		1024

typedef enum { 
  LIST_DIRECTORY = 1, CHANGE_DIRECTORY,
  PWD, RM, MV, CP, NOTHING,
} COMMAND;

typedef struct		s_message_header
{
  COMMAND		command;
  char			command_arguments[NB_READ];
  char			command_arguments2[NB_READ];
}			t_message_header;

typedef struct		s_flag
{
  char			cmd[NB_READ];
  COMMAND		command;
}			t_flag;

void			*xmalloc(int size);

#endif			/* !MESSAGE_H_ */
