/*
** ls_dir.c for ls in /home/marten_a//fluzifix/server
** 
** Made by alexandre martens
** Login   <marten_a@epitech.net>
** 
** Started on  Thu Jul 25 14:29:10 2013 alexandre martens
** Last update Mon Jul 29 21:46:41 2013 alexandre martens
*/

#include	<stdio.h>
#include	<sys/types.h>
#include	<dirent.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	"../server/server.h"

int		check_dir(char *tmp, t_client *client, t_message_header header)
{
  if (chdir(tmp) == -1)
    {
      client->response = malloc(sizeof(char) * NB_READ);
      bzero(client->response, NB_READ);
      client->response_size =  strlen("No such file or directory.\n") + 1;
      memcpy(client->response, "No such file or directory.\n",
	     strlen("No such file or directory.\n"));
      return (1);
    }
  return (0);
}

int		ls_dir(t_client *client, t_message_header header)
{
  DIR		*dp;
  struct dirent *ep;
  char		*res = malloc(sizeof(char) * NB_READ);
  int		i = 0;
  char		tmp[NB_READ];
  int		size = 0;

  bzero(tmp, strlen(tmp));
  memcpy(tmp, client->all_path, strlen(client->all_path) + 1);
  strcat(tmp, "/");
  if (!header.command_arguments[0])
    memcpy(header.command_arguments, ".", strlen("."));
  strcat(tmp, header.command_arguments); 
  if (check_dir(tmp, client, header) == 0)
    {
      dp = opendir (tmp);     
      if (dp != NULL)
	{
	  bzero(res, strlen(res));
	  while (ep = readdir (dp))
	    {
	      size += ep->d_reclen;
	      res = realloc(res, sizeof(char) * size);
	      strcat(res, ep->d_name);
	      strcat(res, "\n");
	    }
	  (void) closedir (dp);
	  client->response = malloc(sizeof(char) * strlen(res));
	  memcpy(client->response, res, strlen(res) + 1);
	  client->response_size = strlen(client->response) +1;
	  
	}
    }
  return 0;
}
