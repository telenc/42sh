/*
** set_env.c for set_env in /home/bodart/projets/Tek1/42sh
** 
** Made by BODART Louis
** Login   <bodart@bodart-l-pc>
** 
** Started on  Sat May 18 15:49:49 2013 BODART Louis
** Last update Sun May 26 13:34:32 2013 BODART Louis
*/

#include	<stdlib.h>
#include	"parser.h"
#include	"lib.h"

int		setenv_utilisation()
{
  my_printf("dtsh: setenv: Invalid arguments\n");
  my_printf("Usage: setenv <var_name> [var_value]\n");
  return (-1);
}

int		my_tablen(char **cmd)
{
  int		i;

  i = 0;
  while (cmd[i])
    i++;
  return (i);
}

int		builtin_setenv(t_link *link, char **cmd)
{
  t_env		*var_ptr;

  if (my_tablen(cmd) < 2 || my_tablen(cmd) > 3)
    return (setenv_utilisation());
  if ((var_ptr = get_var_pointer(link, cmd[1])) != NULL)
    {
      free(var_ptr->value);
      if (!cmd[2])
	var_ptr->value = my_strdup("");
      else
	var_ptr->value = my_strdup(cmd[2]);
      return (42);
    }
  if (!cmd[2])
    link->env = env_var_in_list(link->env, cmd[1], "");
  else
    link->env = env_var_in_list(link->env, cmd[1], cmd[2]);
  return (42);
}
