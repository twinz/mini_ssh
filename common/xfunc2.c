/*
** xfunc2.c for xfunc in /home/marten_a//fluzifix/common
** 
** Made by alexandre martens
** Login   <marten_a@epitech.net>
** 
** Started on  Sun Jul 28 21:25:54 2013 alexandre martens
** Last update Sun Jul 28 21:29:23 2013 alexandre martens
*/

#include		<stdlib.h>
#include		<stdio.h>
#include		<stdlib.h>
#include		<netdb.h>
#include		<sys/types.h>
#include		<sys/socket.h>

int			xwrite(int fd, void *buff, int by)
{
  int			ret;
 
  if ((ret = write(fd, buff, by)) == -1)
    {
      printf("Error write\n");
      exit(0);
    }
  return (ret);
}


int			xsocket(int domain, int type, int protocol)
{
  int			sock;

  if ((sock = socket(domain, type, protocol)) < 0)
    printf("Socket Error.\n");
  return (sock);
}

void			xbind(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
{
  if (bind(sockfd, addr, addrlen) == -1)
    printf("Bind Error.\n");
}

void			xlisten(int sockfd, int backlog)
{
  if (listen(sockfd, backlog) == -1)
    printf("Listen Error.\n");
}

int			xaccept(int sockfd, struct sockaddr *addr, socklen_t *addrlen)
{
  int			fd;

  fd = accept(sockfd, addr, addrlen);
  if (fd == -1)
    {
      printf("Listen Error.\n");
      exit(0);
    }
  return (fd);
}
