/*
** what_is_it.c for what_is_it in /home/ballen_d/42
** 
** Made by lyto
** Login   <ballen_d@lyto>
** 
** Started on  Mon May 13 09:47:07 2013 lyto
** Last update Sun May 26 14:12:33 2013 martre_s
*/

#include	<stdlib.h>
#include	"alias.h"
#include	"parser.h"
#include	"lib.h"

static t_local	*add_a_new_local(t_local *list, char *var, char *val)
{
  t_local	*new_maillon;
  t_local	*tmp;

  tmp = list;
  if (!(new_maillon = my_malloc(sizeof(t_local))))
    return (list);
  new_maillon->variable = my_strdup(var);
  new_maillon->value = my_strdup(val);
  new_maillon->nxt = NULL;
  if (list == NULL)
    return (new_maillon);
  while (tmp->nxt != NULL)
    tmp = tmp->nxt;
  tmp->nxt = new_maillon;
  return (list);
}

static int	check_if_exist(t_local *loc, char *str)
{
  t_local	*tmp;

  tmp = loc;
  while (tmp->nxt != NULL)
    {
      if (my_strcmp(tmp->variable, str) == 0)
	return (-1);
      tmp = tmp->nxt;
    }
  return (0);
}

static t_local	*change_the_value(t_local *loc, char *var,
					  char *val)
{
  t_local	*tmp;

  tmp = loc;
  while (my_strcmp(tmp->variable, var) != 0)
    tmp = tmp->nxt;
  tmp->value = my_strdup(val);
  return (tmp);
}

t_local		*what_is_it(t_local *loc, char *str)
{
  char		**cmd;
  char		*variable;
  int		i;
  int		j;

  i = 0;
  j = 0;
  cmd = my_explode(str, '=');
  if (!(variable = my_malloc(sizeof(char) * (my_strlen(str) + 1))))
    return (loc);
  if (str[0] == '$')
    if (cmd[1] != NULL)
      {
	while (cmd[0][i] == '$')
	  i++;
	while (cmd[0][i] != '\0')
	  variable[j++] = cmd[0][i++];
	if (check_if_exist(loc, variable) == 0)
	  add_a_new_local(loc, variable, cmd[1]);
	else
	  change_the_value(loc, variable, cmd[1]);
      }
  return (loc);
}
