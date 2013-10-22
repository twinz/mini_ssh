/*
** mv_dir.c for mv in /home/marten_a//fluzifix/common
** 
** Made by alexandre martens
** Login   <marten_a@epitech.net>
** 
** Started on  Sun Jul 28 19:00:15 2013 alexandre martens
** Last update Mon Jul 29 21:07:42 2013 alexandre martens
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	<string.h>
#include	<dirent.h>
#include	"../server/server.h"
#include	"../common/message.h"

void		response(t_client *client)
{
  client->response_size =  strlen("") + 1;
  memcpy(client->response, "", strlen(""));
}

int		mv_dir(t_client *client, t_message_header header)
{
  DIR		*dir;

  client->response = xmalloc(sizeof(char) * NB_READ);
  bzero(client->response, NB_READ);
  if ((dir = opendir(header.command_arguments2)) == NULL)
    {
      int n = rename(header.command_arguments, header.command_arguments2);

      if (n != 0)
	{
	  client->response_size =  strlen("No such file or directory\n") + 1;
	  memcpy(client->response, "No such file or directory\n",
		 strlen("No such file or directory\n"));
	}
      else
	response(client);
    }
  else
    {
      cp_dir(client, header);
      rm_dir(client, header);
      response(client);
    }
}
