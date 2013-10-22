/*
** add_commande.c for client in /home/marten_a//fluzifix/client
** 
** Made by alexandre martens
** Login   <marten_a@epitech.net>
** 
** Started on  Wed Jul 24 17:03:48 2013 alexandre martens
** Last update Mon Jul 29 21:43:33 2013 alexandre martens
*/

#include		<string.h>
#include		<stdio.h>
#include		<unistd.h>
#include		<stdlib.h>
#include		"../common/message.h"

t_flag			flags[] = {
  {"ls", LIST_DIRECTORY},
  {"cd", CHANGE_DIRECTORY},
  {"pwd", PWD},
  {"rm", RM},
  {"mv", MV},
  {"cp", CP},
  {0,0}
};

int			count_word(char *str, char c)
{
  int			i;
  int			j;

  i = 0;
  j = 0;
  while (str[i] != 0)
  {
    if (str[i] == c)
      j++;
    i++;
  }
  return (i + 1);
}

int			my_strnlen(char *str, char c)
{
  int			i;

  i = 0;
  while (str[i] && str[i] != c)
    i++;
  return (i);
}

char			**my_str_to_word_tab(char *str, char c)
{
  char			**result;
  int			i;
  int			j;
  int			count;

  i = -1;
  count = 0;
  if (str == NULL)
    return (NULL);
  result = xmalloc((count_word(str, c) + 1) * sizeof(*result));
  while (++i < count_word(str, c))
    {
      while (str[count] == c)
	count++;
      result[i] = xmalloc(my_strnlen(&str[count], c) + 1);
      j = -1;
      while (str[count] != c && str[count] != 0 && str[count] != '\n')
	{
	  result[i][++j] = str[count];
	  count++;
	}
      result[i][j + 1] = '\0';
    }
  result[i] = NULL;
  return (result);
}


int			check_flag(char *str)
{
  int			i;

  i = 0;
  while (flags[i].command)
  {
    if (strcmp(str, flags[i].cmd) == 0)
      return i;
   i++;
 }
  return (-1);
}

t_message_header	*construct_message(char *buffer)
{
  t_message_header	*msg;
  char			**test;

  msg = xmalloc(sizeof(t_message_header));
  test = my_str_to_word_tab(buffer, ' ');
  msg->command_arguments[0] = 0;
  if (test[0]) {
    int i = check_flag(test[0]);
    if (i != -1) {
      msg->command = flags[i].command;

      if (test[1])
        memcpy(msg->command_arguments, test[1], NB_READ);
      if (test[2])
        memcpy(msg->command_arguments2, test[2], NB_READ);
    }
    else
      {
	msg->command = NOTHING;
	memcpy(msg->command_arguments, test[0], NB_READ);
      }
  }   
  return (msg);
}
