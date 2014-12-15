/*
** unset_env.c for unset_env in /home/bodart/projets/Tek1/42sh
** 
** Made by BODART Louis
** Login   <bodart@bodart-l-pc>
** 
** Started on  Sat May 18 16:10:37 2013 BODART Louis
** Last update Sun May 26 16:26:48 2013 BODART Louis
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	"lib.h"
#include	"parser.h"

int		unsetenv_utilisation()
{
  my_printf("dtsh: unsetenv: Invalid arguments\n");
  my_printf("Usage: unsetenv <var_name>\n");
  return (-1);
}

t_env		*get_previous_var(t_link *link, char *var)
{
  t_env		*tmp;

  tmp = link->env;
  if (tmp == NULL)
    return (NULL);
  if (!my_strcmp(tmp->name, var))
    return (tmp);
  while (tmp->nxt != NULL)
    {
      if (!my_strcmp(tmp->nxt->name, var))
	return (tmp);
      tmp = tmp->nxt;
    }
  return (NULL);
}

int		builtin_unsetenv(t_link *link, char **cmd)
{
  t_env		*var_ptr;
  t_env		*tmp;

  if (my_tablen(cmd) != 2)
    return (unsetenv_utilisation());
  if ((var_ptr = get_previous_var(link, cmd[1])) != NULL)
    {
      if (var_ptr == link->env)
	{
	  link->env = var_ptr->nxt;
	  free(var_ptr);
	}
      else
	{
	  tmp = var_ptr->nxt;
	  var_ptr->nxt = var_ptr->nxt->nxt;
	  free(tmp);
	}
      return (42);
    }
  fprintf(stderr, "dtsh: unsetenv: %s doesn't exist\n", cmd[1]);
  return (42);
}
