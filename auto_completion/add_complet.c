/*
** add_complet.c for add_complet in /home/telenc_r/rendu/42sh/42sh-2017-bodart_l
** 
** Made by telenc_r
** Login   <telenc_r@telenc>
** 
** Started on  Sun May 26 11:44:45 2013 telenc_r
** Last update Sun May 26 18:11:14 2013 telenc_r
*/

#include	<sys/types.h>
#include	<dirent.h>
#include	<unistd.h>
#include	"parser.h"
#include	"completion.h"
#include	"lib.h"

extern t_complet	*add_completion(char *name, t_complet *list)
{
  t_complet		*new;
  t_complet		*tmp;

  if (!(new = my_malloc(sizeof(t_complet))))
    return (list);
  new->name = my_strdup(name);
  new->nxt = NULL;
  tmp = list;
  if (tmp == NULL)
    return (new);
  while (tmp->nxt != NULL)
    tmp = tmp->nxt;
  tmp->nxt = new;
  return (list);
}

extern t_complet	*add_path_completion(t_complet *result,
					     t_link *link, char *word)
{
  t_env			*path;
  struct dirent		*lect;
  DIR			*rep;
  char			**list_path;
  int			i;

  path = get_line_env("PATH", link);
  if (path == NULL)
    return (result);
  list_path = my_explode(path->value, ':');
  i = 0;
  while (list_path[i] != NULL)
    {
      rep = opendir(list_path[i]);
      if (rep != 0)
	while ((lect = readdir(rep)))
	  if (my_strncmp(word, lect->d_name, my_strlen(word)) == 0)
	    result = add_completion(lect->d_name, result);
      i++;
    }
  return (result);
}

static int	last_slash(char *str)
{
  int		i;
  int		res;

  i = 0;
  res = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '/')
	res = i;
      i++;
    }
  return (res);
}

char		*get_before_sla(char *str)
{
  char		*result;
  int		i;
  int		pos;

  i = 0;
  result = my_malloc(sizeof(char) * (my_strlen(str) + 1));
  if (result == NULL || str == NULL || contain(str, '/') == FALSE)
    return (NULL);
  pos = last_slash(str);
  while (i <= pos)
    {
      result[i] = str[i];
      i++;
    }
  result[i] = '\0';
  return (result);
}
