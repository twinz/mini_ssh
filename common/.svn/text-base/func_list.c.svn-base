/*
** func_list.c for server in /home/marten_a//fluzifix/server
** 
** Made by alexandre martens
** Login   <marten_a@epitech.net>
** 
** Started on  Tue Jul 23 19:56:26 2013 alexandre martens
** Last update Sun Jul 28 21:05:20 2013 alexandre martens
*/

#include	"../server/server.h"
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<strings.h>


int		my_put_in_list(t_client **begin, int fd)
{
  t_client	*tmp;

  tmp = xmalloc(sizeof(t_client));
  if (tmp == NULL)
    return (1);
  tmp->fd = fd;
  tmp->response_size = 0;
  tmp->response = NULL;
  bzero(tmp->all_path, NB_READ);
  memcpy(tmp->all_path, "/home", strlen("/home") + 1);
  tmp->next = *begin;
  *begin = tmp;
  return (0);
}
