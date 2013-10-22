/*
** server.h for server in /home/marten_a//fluzifix/server
** 
** Made by alexandre martens
** Login   <marten_a@epitech.net>
** 
** Started on  Tue Jul 23 20:17:13 2013 alexandre martens
** Last update Mon Jul 29 21:40:45 2013 alexandre martens
*/

#ifndef			CLIENT_H_
# define		CLIENT_H_

typedef struct		s_client
{
  int sockfd;
}			t_client;

/* client.c */
void			loop(t_client *client);

/* command.c */
int			count_word(char *str, char c);
int			my_strnlen(char *str, char c);
char			**my_str_to_word_tab(char *str, char c);
int			check_flag(char *str);
t_message_header	*construct_message(char *buffer);

#endif			/* !CLIENT_H */
