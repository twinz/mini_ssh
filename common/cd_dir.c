/*
** cd_dir.c for cd in /home/marten_a//fluzifix/server
** 
** Made by alexandre martens
** Login   <marten_a@epitech.net>
** 
** Started on  Thu Jul 25 14:50:18 2013 alexandre martens
** Last update Mon Jul 29 21:11:08 2013 alexandre martens
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<string.h>
#include	"../server/server.h"


int		check(t_client *client, t_message_header header, char *tmp)
{
 if (chdir(client->all_path) == -1)
    {
      bzero(client->all_path, strlen(client->all_path));
      memcpy(client->all_path, tmp, strlen(tmp) + 1);
      client->response = xmalloc(sizeof(char) * NB_READ);
      bzero(client->response, NB_READ);
      client->response_size =  strlen("No such file or directory.\n") + 1;
      memcpy(client->response, "No such file or directory.\n",
	     strlen("No such file or directory.\n"));
      return (1);
    }
 return (0);
}

int		cd_dir(t_client *client, t_message_header header)
{
  char		tmp[NB_READ];

  memcpy(tmp, client->all_path, strlen(client->all_path) + 1);
  if (!header.command_arguments[0])
    {
      bzero(client->all_path, strlen(client->all_path));
      memcpy(client->all_path, "/home", strlen("/home"));
    }
  else
    {
      strcat(client->all_path, "/");
      strcat(client->all_path, header.command_arguments);
    }
  if (check(client, header, tmp) == 0)
    {
      client->response = xmalloc(sizeof(char));
      bzero(client->response, strlen(client->response));
      response(client);
    }
}
