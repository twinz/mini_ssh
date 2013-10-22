/*
** pwd.c for pwd in /home/marten_a//fluzifix/common
** 
** Made by alexandre martens
** Login   <marten_a@epitech.net>
** 
** Started on  Sun Jul 28 19:08:06 2013 alexandre martens
** Last update Mon Jul 29 21:47:30 2013 alexandre martens
*/

#include	<stdio.h>
#include	<sys/types.h>
#include	<dirent.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	"../server/server.h"

int		pwd_dir(t_client *client, t_message_header header)
{
  char		buff[NB_READ];

  client->response = xmalloc(sizeof(char) * NB_READ);
  if (client->all_path)
    {
      bzero(buff, NB_READ);
      strcat(buff,  client->all_path);
      strcat(buff,  "\n");
      bzero(client->response, NB_READ);
      memcpy(client->response, buff, strlen(buff) + 1);
      client->response_size =  strlen(buff) + 1;
    }
}
