/*
** local_var.c for local_var in /home/bodart/projets/Tek1/42sh/builtins
** 
** Made by BODART Louis
** Login   <bodart@bodart-l-pc>
** 
** Started on  Fri May 24 11:16:40 2013 BODART Louis
** Last update Sun May 26 17:43:49 2013 telenc_r
*/

#include	<stdlib.h>
#include	"parser.h"
#include	"lib.h"

char		*check_quote(char *str)
{
  int		i;

  i = 0;
  if (str[i] == '"' || str[i] == '\'')
    {
      while (str[i] != '\0')
	{
	  str[i] = str[i + 1];
	  i++;
	}
      i = my_strlen(str);
      i--;
      if (str[i] == '"' || str[i] == '\'')
	str[i] = '\0';
    }
  return (str);
}

char		**remove_all_quote(char **cmd)
{
  int		i;

  i = 0;
  while (cmd[i])
    {
      cmd[i] = check_quote(cmd[i]);
      i++;
    }
  return (cmd);
}

t_local		*add_local(t_local *local, char *name, char *value)
{
  t_local	*new_local;
  t_local	*tmp;

  if (!(new_local = my_malloc(sizeof(t_local))))
    return (local);
  new_local->variable = my_strdup(name);
  new_local->value = my_strdup(check_quote(value));
  new_local->nxt = NULL;
  if (local == NULL)
    return (new_local);
  tmp = local;
  while (tmp->nxt != NULL)
    tmp = tmp->nxt;
  tmp->nxt = new_local;
  return (local);
}

char		**cut_input(char *str)
{
  int		i;
  int		j;
  char		**array;

  i = 0;
  j = 0;
  if (!(array = my_malloc(sizeof(char *) * 3)))
    return (NULL);
  array[0] = my_malloc(sizeof(char) * (my_strlen(str) + 1));
  if (array[0])
    array[0] = my_memset(array[0], 0, (my_strlen(str) + 1));
  array[1] = my_malloc(sizeof(char) * (my_strlen(str) + 1));
  if (array[1])
    array[1] = my_memset(array[1], 0, (my_strlen(str) + 1));
  while (array[0] && str[i] && str[i] != '=')
    array[0][j++] = str[i++];
  j = 0;
  if (str[i])
    i++;
  while (array[1] && str[i])
    array[1][j++] = str[i++];
  array[2] = NULL;
  return (array);
}

int		local_var(t_link *link, char **cmd)
{
  char		**cutted;
  int		i;
  t_local	*loc;

  i = 0;
  while (cmd[i])
    {
      if (my_count_char(cmd[i], '=') > 0)
	{
	  cutted = cut_input(cmd[i]);
	  if ((loc = get_local_pointer(link, cutted[0])))
	    {
	      loc->value = my_strdup(check_quote(cutted[1]));
	    }
	  else
	    link->local = add_local(link->local, cutted[0], cutted[1]);
	  free(cutted[0]);
	  free(cutted[1]);
	  free(cutted);
	}
      i++;
    }
  return (42);
}
