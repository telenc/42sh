/*
** env_var.c for env_var in /home/bodart/projets/Tek1/42sh
** 
** Made by BODART Louis
** Login   <bodart@bodart-l-pc>
** 
** Started on  Fri May 17 12:07:26 2013 BODART Louis
** Last update Sat May 25 13:54:37 2013 telenc_r
*/

#include	<stdlib.h>
#include	"parser.h"
#include	"lib.h"

t_env		*get_var_pointer(t_link *link, char *var)
{
  t_env		*tmp;

  tmp = link->env;
  while (tmp != NULL)
    {
      if (!my_strcmp(tmp->name, var))
	return (tmp);
      tmp = tmp->nxt;
    }
  return (NULL);
}

char		*get_var_value(t_link *link, char *var)
{
  t_env		*tmp;

  tmp = link->env;
  while (tmp != NULL)
    {
      if (!my_strcmp(tmp->name, var))
	return (tmp->value);
      tmp = tmp->nxt;
    }
  return (NULL);
}

t_local		*get_local_pointer(t_link *link, char *var)
{
  t_local	*tmp;

  tmp = link->local;
  while (tmp != NULL)
    {
      if (!my_strcmp(tmp->variable, var))
	return (tmp);
      tmp = tmp->nxt;
    }
  return (NULL);
}

char		*get_local_value(t_link *link, char *var)
{
  t_local	*tmp;

  tmp = link->local;
  while (tmp != NULL)
    {
      if (!my_strcmp(tmp->variable, var))
	return (tmp->value);
      tmp = tmp->nxt;
    }
  return (NULL);
}
