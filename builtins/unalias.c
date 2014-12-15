/*
** unalias.c for unalias in /home/ballen_d
** 
** Made by lyto
** Login   <ballen_d@lyto>
** 
** Started on  Thu May 23 15:27:22 2013 lyto
** Last update Sun May 26 16:23:47 2013 telenc_r
*/

#include	<stdio.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	"alias.h"
#include	"parser.h"
#include	"lib.h"

static t_alias	*unalias(t_alias *alias, char *str)
{
  t_alias	*save;
  t_alias	*tmp;

  tmp = alias;
  if (str == NULL)
    return (tmp);
  if (tmp != NULL && my_strcmp(tmp->alias, str) == 0)
    {
      save = tmp;
      tmp = tmp->nxt;
      free(save);
      return (tmp);
    }
  while (tmp != NULL && tmp->nxt != NULL
	 && my_strcmp(tmp->nxt->alias, str) != 0)
    tmp = tmp->nxt;
  if (tmp != NULL && tmp->nxt != NULL)
    {
      save = tmp->nxt;
      tmp->nxt = tmp->nxt->nxt;
      free(save);
    }
  return (alias);
}

int		builtin_unalias(t_link *link, char **cmd)
{
  if (cmd[1])
    link->alias = unalias(link->alias, cmd[1]);
  else
    fprintf(stderr, "Malloc failed\n");
  return (TRUE);
}
