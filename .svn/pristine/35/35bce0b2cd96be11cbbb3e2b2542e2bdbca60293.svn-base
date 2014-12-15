/*
** alias.c for alias in /home/ballen_d
** 
** Made by lyto
** Login   <ballen_d@lyto>
** 
** Started on  Thu May  2 09:46:00 2013 lyto
** Last update Sun May 26 17:14:13 2013 telenc_r
*/

#include	<stdio.h>
#include	<sys/types.h>
#include	<unistd.h>
#include	<fcntl.h>
#include	<stdlib.h>
#include	"get_next_line.h"
#include	"alias.h"
#include	"parser.h"
#include	"lib.h"

static t_alias	*add_a_new_alias(t_alias *list, char *alias, char *cmd)
{
  t_alias	*new_maillon;
  t_alias	*tmp;

  tmp = list;
  if (!(new_maillon = my_malloc(sizeof(t_alias))))
    return (list);
  new_maillon->alias = my_strdup(alias);
  new_maillon->cmd = my_strdup(cmd);
  new_maillon->nxt = NULL;
  if (list == NULL)
    return (new_maillon);
  while (tmp->nxt != NULL)
    tmp = tmp->nxt;
  tmp->nxt = new_maillon;
  return (list);
}

static t_alias	*is_alias(t_alias *list, char *str)
{
  char		*cmd;
  char		*alias;
  int		j;
  int		i;

  alias = my_malloc(sizeof(char) * (my_strlen(str) + 1));
  cmd = my_malloc(sizeof(char) * (my_strlen(str) + 1));
  if (alias && cmd && is_an_egal(str) == 0)
    {
      j = 0;
      i = 0;
      while (str[i] != '=')
	alias[j++] = str[i++];
      j = (alias[j] = '\0');
      i++;
      while (str[i] != '\0')
	cmd[j++] = str[i++];
      cmd[j] = '\0';
      cmd = check_quote(cmd);
      if (alias_exist(list, alias) == 0)
	change_the_alias(list, alias, cmd);
      else if (alias_exist(list, alias) == -1)
	list = add_a_new_alias(list, alias, cmd);
    }
  return (list);
}

int		builtin_alias(t_link *link, char **cmd)
{
  int		i;

  if (cmd[1] == NULL)
    display_alias(link->alias);
  else
    {
      i = 1;
      while (cmd[i] != NULL)
	link->alias = is_alias(link->alias, cmd[i++]);
    }
  return (TRUE);
}

extern int	take_my_bashrc(t_link *all, char *path)
{
  t_local	*loc;
  char		*str;
  int		fd;

  loc = all->local;
  fd = open(path, O_RDONLY);
  if (fd == -1)
    {
      fprintf(stderr, "dtsh: Cannot open %s\n", path);
      return (FALSE);
    }
  while ((str = get_next_line(fd)))
    if (str[0] != '#' && str[0] != '\0')
      get_command_line(all, str, 0);
    else
      loc = what_is_it(loc, str);
  close(fd);
  return (TRUE);
}

char		*check_in_alias(t_alias *alias, char *str)
{
  t_alias	*tmp;

  tmp = alias;
  if (str == NULL)
    return (NULL);
  while (tmp != NULL)
    {
      if (my_strcmp(str, tmp->alias) == 0)
	{
	  return (tmp->cmd);
	}
      tmp = tmp->nxt;
    }
  return (NULL);
}
