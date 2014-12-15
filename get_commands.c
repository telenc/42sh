/*
** get_commands.c for get_commands in /home/bodart/projets/Tek1/42sh
** 
** Made by BODART Louis
** Login   <bodart@bodart-l-pc>
** 
** Started on  Fri May 17 11:51:09 2013 BODART Louis
** Last update Sun May 26 18:54:29 2013 telenc_r
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"parser.h"
#include	"lib.h"

int		is_exec(char *str)
{
  struct stat	file_stat;

  lstat(str, &file_stat);
  if ((file_stat.st_mode > 0) && S_ISREG(file_stat.st_mode))
    return (1);
  return (0);
}

char		*check_path_commands(t_link *link, char *str)
{
  int		i;
  char		**path;
  char		*tmp;
  char		*old;
  char		*var_value;

  i = 0;
  var_value = get_var_value(link, "PATH");
  if (var_value == NULL)
    return (NULL);
  path = my_explode(var_value, ':');
  old = my_strcat("/", str);
  if (str[0] != '/')
    {
      while (path[i])
	{
	  tmp = my_strcat(path[i++], old);
	  if (!access(tmp, X_OK))
	    return (tmp);
	  free(tmp);
	}
    }
  if (access(str, X_OK) == 0 && is_exec(str))
    return (my_strdup(str));
  return (NULL);
}

char		*get_full_command(t_link *link, char *str)
{
  char		*new;

  if (is_built(str, link) != NULL)
    return (str);
  if ((new = check_path_commands(link, str)) != NULL)
    {
      free(str);
      return (new);
    }
  if (is_built(str, link))
    return (str);
  return (NULL);
}
