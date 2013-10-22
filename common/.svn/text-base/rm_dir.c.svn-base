/*
** rm_dir.c for rm in /home/marten_a//fluzifix/common
** 
** Made by alexandre martens
** Login   <marten_a@epitech.net>
** 
** Started on  Sun Jul 28 19:00:45 2013 alexandre martens
** Last update Mon Jul 29 21:09:14 2013 alexandre martens
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	<string.h>
#include	"../server/server.h"

int		rm_dir(t_client *client, t_message_header header)
{
  client->response = xmalloc(sizeof(char) * NB_READ);
  bzero(client->response, NB_READ);


  int n = remove(header.command_arguments);

  if (n != 0)
    {
      client->response_size =  strlen("No such file or directory\n") + 1;
      memcpy(client->response, "No such file or directory\n",
	     strlen("No such file or directory\n"));
    }
  else
    response(client);
}
