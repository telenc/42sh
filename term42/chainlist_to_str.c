/*
** chainlist_to_str.c for chainlist_to_str in /home/ballen_d
** 
** Made by lyto
** Login   <ballen_d@lyto>
** 
** Started on  Wed May 22 13:10:11 2013 lyto
** Last update Sun May 26 01:14:09 2013 telenc_r
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"parser.h"
#include	"lib.h"

int		my_count_elem(t_line *line)
{
  t_line	*tmp;
  int		i;

  i = 0;
  tmp = line;
  while (tmp->next != line)
    {
      tmp = tmp->next;
      i++;
    }
  i += 2;
  return (i);
}

char		*convert_list_to_str(t_line *line)
{
  t_line	*tmp;
  char		*cmd;
  int		i;

  i = 0;
  tmp = line;
  if (tmp == NULL)
    return (my_strdup(""));
  if (!(cmd = my_malloc(my_count_elem(line) * sizeof(char))))
    return (NULL);
  while (tmp != NULL && tmp->next != line)
    {
      cmd[i] = tmp->arg;
      tmp = tmp->next;
      i++;
    }
  cmd[i++] = tmp->arg;
  cmd[i] = '\0';
  return (cmd);
}

t_line		*convert_str_to_list(char *str)
{
  t_line	*tmp;
  int		i;

  i = 0;
  tmp = NULL;
  str = my_epur_str(str);
  while (str[i] != '\0')
    tmp = put_in_list(tmp, str[i++]);
  return (tmp);
}
