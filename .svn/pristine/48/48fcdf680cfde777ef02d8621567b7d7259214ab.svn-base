/*
** auto_complet.c for auto_complet in /home/telenc_r/rendu/42sh/my/auto_completion
** 
** Made by telenc_r
** Login   <telenc_r@telenc>
** 
** Started on  Thu May 16 09:41:15 2013 telenc_r
** Last update Sun May 26 19:36:27 2013 telenc_r
*/

#include	<sys/types.h>
#include	<dirent.h>
#include	<unistd.h>
#include	"lib.h"
#include	"parser.h"
#include	"completion.h"

static int		size_auto_complet(t_complet *complet)
{
  t_complet		*tmp;
  int			i;

  tmp = complet;
  i = 0;
  while (tmp != NULL)
    {
      tmp = tmp->nxt;
      i++;
    }
  return (i);
}

extern t_complet	*auto_completion(char *word, t_link *link, int check_path)
{
  struct dirent		*lect;
  DIR			*rep;
  t_complet		*result;
  char			*path;

  result = NULL;
  path = get_before_sla(word);
  if (path == NULL)
    rep = opendir(".");
  else
    rep = opendir(path);
  while (contain(word, '/') == TRUE)
    word = my_strcut(word, 1);
  if (rep == 0)
    return (NULL);
  while ((lect = readdir(rep)))
    if (word[0] == '\0' || my_strncmp(word, lect->d_name,
				      my_strlen(word)) == 0)
      result = add_completion(lect->d_name, result);
  if (check_path == 1 && path == NULL)
    result = add_path_completion(result, link, word);
  return (result);
}

static int	return_one_completion(int i, char **cmd,
				      t_link *link, t_complet *complet)
{
  char		*str;

  if (i != 1)
    {
      i = 0;
      str = my_strdup("");
      while (cmd[i + 1] != NULL)
	str = my_strcat(str, cmd[i++]);
    }
  i = 0;
  str = my_strdup("");
  while (cmd[i] && cmd[i + 1])
    {
      str = my_strcat(str, cmd[i++]);
      str = my_strcat(str, " ");
    }
  str = my_strcat(str, complet->name);
  link->line = convert_str_to_list(str);
  return (TRUE);
}

static int	return_mult_completion(t_complet *complet)
{
  if (complet == NULL)
    return (TRUE);
  my_putchar('\n');
  while (complet != NULL)
    {
      my_printf("%s\n", complet->name);
      complet = complet->nxt;
    }
  return (FALSE);
}

int		term_auto_completion(t_link *link)
{
  t_complet	*complet;
  char		*str;
  char		**cmd;
  char		*path;

  if (link->line != NULL)
    {
      str = convert_list_to_str(link->line);
      cmd = my_explode(str, ' ');
      if (my_tablen(cmd) > 0)
	path = get_before_sla(cmd[my_tablen(cmd) - 1]);
      if (my_tablen(cmd) == 1)
	complet = auto_completion(cmd[my_tablen(cmd) - 1], link, 1);
      else
	complet = auto_completion(cmd[my_tablen(cmd) - 1], link, 0);
      if (size_auto_complet(complet) == 1)
	{
	  if (path != NULL)
	    complet->name = my_strcat(path, complet->name);
	  return (return_one_completion(my_tablen(cmd), cmd, link, complet));
	}
      else
	return (return_mult_completion(complet));
    }
  return (TRUE);
}
