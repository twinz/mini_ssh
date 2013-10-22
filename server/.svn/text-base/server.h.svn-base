/*
** server.h for server in /home/marten_a//fluzifix/common
** 
** Made by alexandre martens
** Login   <marten_a@epitech.net>
** 
** Started on  Sun Jul 28 19:11:29 2013 alexandre martens
** Last update Mon Jul 29 21:41:47 2013 alexandre martens
*/

#ifndef			SERVER_H_
# define		SERVER_H_

#include		"../common/message.h"

typedef struct		s_client
{
  int			fd;
  char			all_path[NB_READ];
  int			response_size;
  char			*response;
  struct s_client	*next;
}			t_client;


typedef struct		s_server
{
  int			sockfd;
  struct s_client	*client_head;
}			t_server;

#endif			/* !SERVER_H_ */
