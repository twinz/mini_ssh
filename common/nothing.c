/*
** modif_file.c for modif in /home/marten_a//fluzifix/server
** 
** Made by alexandre martens
** Login   <marten_a@epitech.net>
** 
** Started on  Sat Jul 27 20:46:44 2013 alexandre martens
** Last update Mon Jul 29 20:38:50 2013 alexandre martens
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	<string.h>
#include	"../server/server.h"

int		nothing(t_client *client, t_message_header header)
{
  client->response = malloc(sizeof(char) * NB_READ);
  bzero(client->response, NB_READ);
  client->response_size =  strlen("command not found\n") + 1;
  memcpy(client->response, "command not found\n", strlen("command not found\n"));
}
