/*
** free_end.c for free_end in /home/bodart/projets/Tek1/42sh/42sh-2017-bodart_l
** 
** Made by BODART Louis
** Login   <bodart@bodart-l-pc>
** 
** Started on  Sun May 26 17:49:27 2013 BODART Louis
** Last update Sun May 26 17:54:51 2013 BODART Louis
*/

#include	<stdlib.h>
#include	"alias.h"
#include	"parser.h"

void		free_local(t_local *local)
{
  t_local	*tmp;
  t_local	*ptr;

  tmp = local;
  while (tmp)
    {
      ptr = tmp;
      tmp = tmp->nxt;
      free(ptr->variable);
      free(ptr->value);
      free(ptr);
    }
}

void		free_alias(t_alias *alias)
{
  t_alias	*tmp;
  t_alias	*ptr;

  tmp = alias;
  while (tmp)
    {
      ptr = tmp;
      tmp = tmp->nxt;
      free(ptr->alias);
      free(ptr->cmd);
      free(ptr);
    }
}

void		free_env(t_env *env)
{
  t_env		*tmp;
  t_env		*ptr;

  tmp = env;
  while (tmp)
    {
      ptr = tmp;
      tmp = tmp->nxt;
      free(ptr->name);
      free(ptr->value);
      free(ptr);
    }
}
