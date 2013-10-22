/*
** server.c for server in /home/marten_a//fluzifix/server
** 
** Made by alexandre martens
** Login   <marten_a@epitech.net>
** 
** Started on  Sun Jul 28 19:11:55 2013 alexandre martens
** Last update Mon Jul 29 21:45:37 2013 alexandre martens
*/

#include		<stdio.h>
#include		<sys/types.h>
#include		<sys/socket.h>
#include		<netinet/in.h>
#include		<stdlib.h>
#include		<string.h>
#include		"server.h"
#include		"../common/message.h"

void			write_server(t_client *cli_it, fd_set writefs)
{
  if (FD_ISSET(cli_it->fd, &writefs))
    {
      t_message_header header;
      int to_write = cli_it->response_size % NB_READ;
      
      to_write = ((to_write == 0 && cli_it->response_size > 0) ? NB_READ : to_write);
      header.command = 1;
      memcpy(header.command_arguments, cli_it->response, to_write);
      
      int written = xwrite(cli_it->fd, &header, sizeof(t_message_header));
      written = written - (sizeof(header) - sizeof(header.command_arguments));
      cli_it->response_size -= written;
      
      if (cli_it->response_size <= 0 && cli_it->response != NULL)
	{
	  free(cli_it->response);
	  cli_it->response_size = 0;
	  cli_it->response = NULL;
	}
    }
}

void			read_server(t_client *cli_it, fd_set readfs)
{
  if (FD_ISSET(cli_it->fd, &readfs))
    {
      t_message_header header;
      int nb_read = read(cli_it->fd, &header, sizeof(header));
      
      if (nb_read <= 0)
	{
	  cli_it->fd = -1;
	  printf("client disconnect\n");
	} 
      else
	{
	  if (header.command == LIST_DIRECTORY)
	    ls_dir(cli_it, header);
	  else if (header.command == CHANGE_DIRECTORY)
	    cd_dir(cli_it, header);
	  else if (header.command == PWD)
	    pwd_dir(cli_it, header);
	  else if (header.command == RM)
	    rm_dir(cli_it, header);
	  else if (header.command == MV)
	    mv_dir(cli_it, header);
	  else if (header.command == CP)
	    cp_dir(cli_it, header);
	  else
	    nothing(cli_it, header);
	}
    }
}

void			stock_info(t_client *cli_it, fd_set readfs, fd_set writefs)
{
  while (cli_it)
    {
      if (cli_it->fd != -1)
	{
	  write_server(cli_it, writefs);
	  read_server(cli_it, readfs);
	}
      cli_it = cli_it->next;
    }
}

void			stock_list(t_server *server, struct sockaddr_in clientname, fd_set readfs)
{
  if (FD_ISSET(server->sockfd, &readfs))
    {
      int clilen = sizeof (clientname);
      int client_socket = xaccept(server->sockfd, (struct sockaddr *) &clientname, &clilen);

      my_put_in_list(&server->client_head, client_socket);
    }
}

void			loop(t_server *server)
{
  fd_set		readfs;
  fd_set		writefs;
  struct sockaddr_in	cli_addr, clientname;
  int			clilen;
  
  clilen = sizeof(cli_addr);
  while(42)
    {
      FD_ZERO(&readfs);
      FD_ZERO(&writefs);
      FD_SET(server->sockfd, &readfs);
      int highsock = server->sockfd;
      t_client* cli_it = server->client_head;
      
      while (cli_it)
	{
	  if (cli_it->fd != -1) {
	    FD_SET(cli_it->fd, &readfs);
	    
	    if (cli_it-> response_size > 0)
	      FD_SET(cli_it->fd, &writefs);
	    if (highsock < cli_it->fd)
	      highsock = cli_it->fd;
	  }
	  cli_it = cli_it->next;
	}
      xselect(highsock + 1, &readfs, &writefs, NULL, NULL);
      cli_it = server->client_head;
      stock_info(cli_it, readfs, writefs);
      stock_list(server, clientname, readfs);
    }
}

int			main(int argc, char *argv[])
{
  t_server		server;
  struct sockaddr_in	serv_addr;
  int			portno;

  server.client_head = NULL;
  if (argc < 2) {
    fprintf(stderr,"ERROR, no port provided\n");
    exit(1);
  }
  server.sockfd = xsocket(AF_INET, SOCK_STREAM, 0);
  bzero((char *) &serv_addr, sizeof(serv_addr));
  portno = atoi(argv[1]);
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(portno);
  
  xbind(server.sockfd, (struct sockaddr *) &serv_addr,
	sizeof(serv_addr));
  xlisten(server.sockfd,5);
  loop(&server);
}
