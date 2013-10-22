/*
** client.c for client in /home/marten_a//fluzifix/server
** 
** Made by alexandre martens
** Login   <marten_a@epitech.net>
** 
** Started on  Sun Jul 28 18:50:43 2013 alexandre martens
** Last update Mon Jul 29 21:57:40 2013 alexandre martens
*/

#include		<stdio.h>
#include		<sys/types.h>
#include		<sys/socket.h>
#include		<netinet/in.h>
#include		<netdb.h>
#include		<unistd.h>
#include		<strings.h>
#include		<stdlib.h>
#include		"../common/message.h"
#include		"client.h"

void			loop(t_client *client)
{
  char		buffer[NB_READ];

  while (42)
    {
      bzero(buffer, NB_READ);
      printf("$> ");
      fgets(buffer,NB_READ - 1,stdin);
   
      t_message_header *send_message = construct_message(buffer);
      if (send_message != NULL) {
	int n = xwrite(client->sockfd, send_message, sizeof(t_message_header));
	free(send_message);
      }

      t_message_header receive_message;
      read(client->sockfd,&receive_message, sizeof(t_message_header));
      printf("%s", receive_message.command_arguments);
    }
}

int			main(int argc, char *argv[])
{
  t_client		client;
  int			portno;
  int			n;
  struct sockaddr_in	serv_addr;
  struct hostent	*server;

    if (argc < 3)
      {
	fprintf(stderr,"usage %s hostname port\n", argv[0]);
	exit(0);
      }
    portno = atoi(argv[2]);
    client.sockfd = xsocket(AF_INET, SOCK_STREAM, 0);
    server = gethostbyname(argv[1]);
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
          (char *)&serv_addr.sin_addr.s_addr,
          server->h_length);
    serv_addr.sin_port = htons(portno);
    xconnect(client.sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));
    loop(&client);
}
