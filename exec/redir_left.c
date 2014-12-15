/*
** redir_left.c for redir_left in /home/telenc_r/rendu/42sh/my/exec
** 
** Made by telenc_r
** Login   <telenc_r@telenc>
** 
** Started on  Sun May 19 14:08:14 2013 telenc_r
** Last update Sun May 26 19:23:12 2013 telenc_r
*/

#include	<fcntl.h>
#include	<unistd.h>
#include	"get_next_line.h"
#include	"parser.h"
#include	"lib.h"

static int	get_next_redir_left(char **cmd, int pos)
{
  while (cmd[pos] != NULL)
    {
      if (my_strcmp(cmd[pos], "<<") == 0)
	return (pos);
      if (my_strcmp(cmd[pos], "<") == 0)
	return (pos);
      pos++;
    }
  return (-1);
}

static int	exec_simple_redir_left(char *str)
{
  int		op;

  op = open(str, O_RDONLY, 0);
  if (op == -1)
    return (FALSE);
  if (dup2(op, 0) == -1)
    return (FALSE);
  return (TRUE);
}

static int	exec_double_redir_left(char *fichier)
{
  char		*str;
  char		*retu;
  int		i;

  retu = my_strdup("");
  while (1)
    {
      str = get_next_line(0);
      if (str == NULL)
	return (TRUE);
      if (my_strcmp(str, fichier) == 0)
	{
	  i = 0;
	  while (retu[i] != '\0')
	    write(1, &(retu[i++]), 1);
	  return (TRUE);
	}
      retu = my_strcat(retu, str);
      retu = my_strcat(retu, "\n");
    }
  return (TRUE);
}

static int	pipe_double_left(char *fichier)
{
  int pid;
  int pipe_fd[2];

  pipe(pipe_fd);
  pid = fork();
  if (pid == 0)
    {
      close(pipe_fd[0]);
      dup2(pipe_fd[1], 1);
      exec_double_redir_left(fichier);
      _exit(0);
    }
  else
    {
      close(pipe_fd[1]);
      dup2(pipe_fd[0], 0);
      close(pipe_fd[0]);
    }
  return (TRUE);
}

extern int	redir_left(char ***str)
{
  char		**cmd;
  char		*fichier;
  int		type;
  int		pos_red;

  cmd = *str;
  pos_red = 0;
  fichier = NULL;
  type = SIMPL_R;
  while ((pos_red = get_next_redir_left(cmd, pos_red)) != -1)
    {
      if (cmd[pos_red + 1] == NULL
	  || check_redir_right(cmd[pos_red + 1]) == FALSE)
	return (FALSE);
      fichier = my_strdup(cmd[pos_red + 1]);
      type = get_type_redir(cmd[pos_red]);
      cmd = my_remove_in_tab(cmd, pos_red);
      cmd = my_remove_in_tab(cmd, pos_red);
    }
  if (type == SIMPL_L && exec_simple_redir_left(fichier) == FALSE)
    return (FALSE);
  if (type == DOUBL_L)
    pipe_double_left(fichier);
  *str = cmd;
  return (TRUE);
}

