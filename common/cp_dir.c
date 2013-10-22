/*
** cp_dir.c for cp in /home/marten_a//fluzifix/common
** 
** Made by alexandre martens
** Login   <marten_a@epitech.net>
** 
** Started on  Sun Jul 28 19:01:39 2013 alexandre martens
** Last update Mon Jul 29 21:10:30 2013 alexandre martens
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	<string.h>
#include	"../server/server.h"

int		check_cp(t_client *client, t_message_header header, int fd_src, int fd_des)
{

  if (fd_des == -1 || fd_src == 1)
    {
      client->response = xmalloc(sizeof(char) * NB_READ);
      bzero(client->response, NB_READ);
      client->response_size =  strlen("cannot copy file\n") + 1;
      memcpy(client->response, "cannot copy file\n",
	     strlen("cannot copy file\n"));
      return (1);
    }
  else
    {
      response(client);
      return (0);
    }
}

int		cp_dir(t_client *client, t_message_header header)
{
  char		src[NB_READ];
  char		des[NB_READ];
  char		buff[NB_READ];
  int		fd_src;
  int		fd_des;
  int		nb_read = 0;

  client->response = malloc(sizeof(char));
  bzero(client->response, strlen(client->response));
  bzero(des, strlen(des));
  bzero(src, strlen(src));

  memcpy(src, header.command_arguments, strlen(header.command_arguments));
  memcpy(des, header.command_arguments2, strlen(header.command_arguments2));

  strcat(des, "/");
  strcat(des, header.command_arguments);
  fd_des = open(des, O_CREAT | O_WRONLY, 0666);
  fd_src = open(src, O_RDONLY);

  if (check_cp(client, header, fd_src, fd_des) == 0)
    {
      while ((nb_read = read(fd_src, buff, NB_READ)) > 0)
	write(fd_des, buff, nb_read);
    }
  close(fd_src);
  close(fd_des);
}
