/*
** convert_environment.c for convert_environment in /home/bodart/projets/Tek1/42sh/42sh-2017-bodart_l
** 
** Made by BODART Louis
** Login   <bodart@bodart-l-pc>
** 
** Started on  Thu May 16 15:09:47 2013 BODART Louis
** Last update Sat May 25 23:09:48 2013 BODART Louis
*/

#include	<stdlib.h>
#include	"parser.h"
#include	"lib.h"

char		*build_env_var(char *name, char *value)
{
  char		*var;
  char		*tmp;

  tmp = my_strcat(name, "=");
  var = my_strcat(tmp, value);
  free(tmp);
  return (var);
}

char		**convert_environment(t_env *env)
{
  char		**cmd;
  t_env		*tmp;
  t_env		*ptr;
  int		i;

  tmp = env;
  ptr = env;
  i = 0;
  while (ptr != NULL)
    {
      i++;
      ptr = ptr->nxt;
    }
  if (!(cmd = my_malloc(sizeof(char *) * (i + 1))))
    return (NULL);
  i = 0;
  while (tmp != NULL)
    {
      cmd[i++] = build_env_var(tmp->name, tmp->value);
      tmp = tmp->nxt;
    }
  cmd[i] = NULL;
  return (cmd);
}
