/*
** xfunc.c for server in /home/marten_a//rattrapage
** 
** Made by alexandre martens
** Login   <marten_a@epitech.net>
** 
** Started on  Tue Jul 23 15:34:26 2013 alexandre martens
** Last update Mon Jul 29 21:56:33 2013 alexandre martens
*/

#include		<stdlib.h>
#include		<stdio.h>
#include		<stdlib.h>
#include		<netdb.h>
#include		<sys/types.h>
#include		<sys/socket.h>



int			xselect(int fds, fd_set *r, fd_set *w,
				fd_set *ex, struct timeval *tv)
{
  if (select(fds, r, w, ex, tv) == -1)
    printf("Select Error.\n");
  return (1);
}

int			xconnect(int sockfd, const struct sockaddr *addr,
				socklen_t addrlen)
{
  if (connect(sockfd, addr, addrlen) == -1)
    {
      printf("Connect Error.\n");
      exit(0);
    }
}

void			*xmalloc(int size)
{
  void			*ptr;

  if ((ptr = malloc(size)) == NULL)
    printf("Malloc Error.\n");
  return (ptr);
}

void			xclose(int fd)
{
  if (close(fd) == -1)
    printf("Close Error.\n");
}

struct protoent		*xgetprotobyname(char *proto)
{
  struct protoent	*pe;

  if ((pe = getprotobyname(proto)) == NULL)
    printf("Getprotobyname Error.\n");
  return (pe);
}

