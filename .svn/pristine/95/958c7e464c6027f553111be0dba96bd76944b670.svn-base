/*
** edit_command.c for edit_command in /home/bodart/projets/Tek1/42sh
** 
** Made by BODART Louis
** Login   <bodart@bodart-l-pc>
** 
** Started on  Thu May 16 19:44:59 2013 BODART Louis
** Last update Sun May 26 17:44:32 2013 telenc_r
*/

#include	<stdlib.h>
#include	"parser.h"
#include	"lib.h"

t_cmd		*add_cmd_element(t_cmd *cmd, char *str)
{
  t_cmd		*new_element;
  t_cmd		*tmp;

  if (!(new_element = my_malloc(sizeof(t_cmd))))
    return (cmd);
  new_element->word = str;
  new_element->nxt = NULL;
  if (cmd == NULL)
    return (new_element);
  tmp = cmd;
  while (tmp->nxt != NULL)
    tmp = tmp->nxt;
  tmp->nxt = new_element;
  return (cmd);
}

char		*check_in_local_var(t_link *link, char *str)
{
  t_local	*tmp;
  char		*cutted;

  tmp = link->local;
  cutted = my_strcut(str, 1);
  while (tmp != NULL)
    {
      if (!my_strcmp(tmp->variable, cutted))
	{
	  free(cutted);
	  return (my_strdup(tmp->value));
	}
      tmp = tmp->nxt;
    }
  free(cutted);
  return (NULL);
}

char		*check_in_env_var(t_link *link, char *str)
{
  t_env		*tmp;
  char		*cutted;
  char		*local;

  tmp = link->env;
  cutted = my_strcut(str, 1);
  while (tmp != NULL)
    {
      if (!my_strcmp(tmp->name, cutted))
	{
	  free(cutted);
	  free(str);
	  return (my_strdup(tmp->value));
	}
      tmp = tmp->nxt;
    }
  if ((local = check_in_local_var(link, str)))
    {
      free(str);
      free(cutted);
      return (local);
    }
  free(str);
  free(cutted);
  return (my_strdup(""));
}

char		**build_new_command(t_cmd *cmd)
{
  int		i;
  char		**new_tab;
  t_cmd		*tmp;

  i = 0;
  tmp = cmd;
  while (tmp != NULL)
    {
      i++;
      tmp = tmp->nxt;
    }
  if (!(new_tab = my_malloc(sizeof(char *) * (i + 1))))
    return (NULL);
  i = 0;
  tmp = cmd;
  while (tmp != NULL)
    {
      new_tab[i++] = my_strdup(tmp->word);
      tmp = tmp->nxt;
    }
  new_tab[i] = NULL;
  return (new_tab);
}

char		**edit_command(t_link *link, char *str)
{
  int		i;
  t_cmd		*cmd;
  char		**tabl;
  char		**new_tab;

  i = 0;
  if (!my_strcmp(str, ".") || !my_strcmp(str, ".."))
    return (NULL);
  tabl = my_explode_cote(str, ' ');
  cmd = NULL;
  while (tabl[i])
    {
      if (cmd == NULL && (tabl[i] = get_full_command(link, tabl[i])) == NULL)
	return (NULL);
      cmd = add_cmd_element(cmd, tabl[i++]);
    }
  new_tab = build_new_command(cmd);
  return (new_tab);
}
