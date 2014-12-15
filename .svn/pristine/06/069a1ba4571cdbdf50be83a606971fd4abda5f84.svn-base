/*
** redir.c for redir in /home/telenc_r/rendu/42sh/my
** 
** Made by telenc_r
** Login   <telenc_r@telenc>
** 
** Started on  Sat May 18 13:03:53 2013 telenc_r
** Last update Sun May 26 10:49:45 2013 telenc_r
*/

#include	<fcntl.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<unistd.h>
#include	"parser.h"
#include	"lib.h"

extern int	is_redir(char *cmd)
{
  if (my_strcmp(cmd, "<<") == 0)
    return (TRUE);
  if (my_strcmp(cmd, "<") == 0)
    return (TRUE);
  if (my_strcmp(cmd, ">") == 0)
    return (TRUE);
  if (my_strcmp(cmd, ">>") == 0)
    return (TRUE);
  return (FALSE);
}

extern int	check_redir_right(char *str)
{
  if (my_strcmp(str, ">>") == 0)
    return (FALSE);
  if (my_strcmp(str, ">") == 0)
    return (FALSE);
  if (my_strcmp(str, "<<") == 0)
    return (FALSE);
  if (my_strcmp(str, "<") == 0)
    return (FALSE);
  return (TRUE);
}

extern int	get_type_redir(char *str)
{
  if (my_strcmp(str, ">>") == 0)
    return (DOUBL_R);
  if (my_strcmp(str, ">") == 0)
    return (SIMPL_R);
  if (my_strcmp(str, "<<") == 0)
    return (DOUBL_L);
  return (SIMPL_L);
}

static int	exec_redir_right(char *str, int type)
{
  int		op;

  if (type == SIMPL_R)
    op = open(str, O_WRONLY | O_NONBLOCK | O_CREAT | O_TRUNC, S_IRWXU);
  else
    op = open(str, O_WRONLY | O_NONBLOCK | O_CREAT | O_APPEND, S_IRWXU);
  if (op == -1)
    return (FALSE);
  if (dup2(op, 1) == -1)
    return (FALSE);
  return (TRUE);
}

extern int	redir_right(char ***str)
{
  char		**cmd;
  char		*fichier;
  int		type;
  int		pos_red;

  cmd = *str;
  pos_red = 0;
  fichier = NULL;
  while ((pos_red = get_next_redir_right(cmd, pos_red)) != -1)
    {
      if (cmd[pos_red + 1] == NULL
	  || check_redir_right(cmd[pos_red + 1]) == FALSE)
	{
	  my_printf("42sh: syntax error near unexprected token 'newline'\n");
	  return (FALSE);
	}
      fichier = my_strdup(cmd[pos_red + 1]);
      type = get_type_redir(cmd[pos_red]);
      cmd = my_remove_in_tab(my_remove_in_tab(cmd, pos_red), pos_red);
    }
  if (fichier != NULL)
    if (exec_redir_right(fichier, type) == FALSE)
      return (FALSE);
  *str = cmd;
  return (TRUE);
}
