/*
** check_alias.c for check_alias in /home/ballen_d/42/ce_que_je_donne_a_louis
** 
** Made by lyto
** Login   <ballen_d@lyto>
** 
** Started on  Thu May 16 11:40:35 2013 lyto
** Last update Thu May 23 16:20:49 2013 martre_s
*/

#include	<unistd.h>
#include	"alias.h"
#include	"lib.h"

t_alias		*change_the_alias(t_alias *list, char *alias, char *cmd)
{
  t_alias	*tmp;

  tmp = list;
  while (my_strcmp(tmp->alias, alias) != 0)
    tmp = tmp->nxt;
  tmp->cmd = my_strdup(cmd);
  return (tmp);
}

int		alias_exist(t_alias *list, char *alias)
{
  t_alias	*tmp;

  tmp = list;
  while (tmp != NULL)
    {
      if (my_strcmp(tmp->alias, alias) == 0)
	return (0);
      tmp = tmp->nxt;
    }
  return (-1);
}

int		is_an_egal(char *str)
{
  int		com;
  int		ret;
  int		i;

  i = 0;
  ret = -1;
  com = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '"')
	com++;
      if (str[i] == '=' && str[i + 1] != '\0' && com == 0)
	ret++;
      i++;
    }
  return (ret);
}

int		is_two_quotes(char *str)
{
  int		ret;
  int		i;

  i = 0;
  ret = -2;
  while (str[i] != '\0')
    {
      if (str[i] == '"')
	ret++;
      i++;
    }
  return (ret);
}
