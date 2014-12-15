/*
** get_environment.c for get_environment in /home/bodart/projets/Tek1/42sh
** 
** Made by BODART Louis
** Login   <bodart@bodart-l-pc>
** 
** Started on  Thu May 16 12:00:38 2013 BODART Louis
** Last update Sun May 26 14:30:53 2013 telenc_r
*/

#include	<stdlib.h>
#include	"parser.h"
#include	"lib.h"

t_env		*env_var_in_list(t_env *env, char *name, char *value)
{
  t_env		*new_var;
  t_env		*tmp;

  if (!(new_var = my_malloc(sizeof(t_env))))
    return (env);
  new_var->name = my_strdup(name);
  new_var->value = my_strdup(check_quote(value));
  new_var->nxt = NULL;
  if (env == NULL)
    return (new_var);
  tmp = env;
  while (tmp->nxt != NULL)
    tmp = tmp->nxt;
  tmp->nxt = new_var;
  return (env);
}

char		**cut_env_var(char *full_var)
{
  char		**cmd;
  int		i;
  int		j;

  i = 0;
  j = 0;
  if (!(cmd = my_malloc(sizeof(char *) * 3)))
    return (NULL);
  cmd[0] = my_malloc(sizeof(char) * (my_strlen(full_var) + 1));
  if (cmd[0])
    cmd[0] = my_memset(cmd[0], 0, (my_strlen(full_var) + 1));
  cmd[1] = my_malloc(sizeof(char) * (my_strlen(full_var) + 1));
  if (cmd[1])
    cmd[1] = my_memset(cmd[1], 0, (my_strlen(full_var) + 1));
  while (cmd[0] && (full_var[i] && full_var[i] != '='))
    cmd[0][j++] = full_var[i++];
  i++;
  j = 0;
  while (cmd[1] && full_var[i])
    cmd[1][j++] = full_var[i++];
  cmd[2] = NULL;
  return (cmd);
}

t_env		*add_env_in_list(t_env *env, char **envp)
{
  char		**cmd;
  int		i;

  i = 0;
  while (envp[i])
    {
      cmd = cut_env_var(envp[i++]);
      if (cmd)
	env = env_var_in_list(env, cmd[0], cmd[1]);
    }
  return (env);
}

t_env		*get_environment(char **envp)
{
  t_env		*env;

  env = NULL;
  if (!envp[0])
    {
      my_printf("BODART FONCTION EFFACER PAR STEVEN A FAIRE\n");
      return (env);
    }
  env = add_env_in_list(env, envp);
  return (env);
}
