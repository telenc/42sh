/*
** cmd_pipe.c for cmd_pipe in /home/telenc_r/rendu/42sh/my/exec
** 
** Made by telenc_r
** Login   <telenc_r@telenc>
** 
** Started on  Fri May 17 09:15:57 2013 telenc_r
** Last update Sun May 26 19:32:43 2013 telenc_r
*/

#include	<sys/types.h>
#include	<sys/wait.h>
#include	<unistd.h>
#include	"parser.h"
#include	"types.h"

static int	exec_father(t_node *node, t_link *link, int pipe_fd[2])
{

  if (close(pipe_fd[1]) == -1)
    return (FALSE);
  if (dup2(pipe_fd[0], 0) == -1)
    return (FALSE);
  if (close(pipe_fd[0]) == -1)
    return (FALSE);
  if (node->type == COMMAND)
    return (exec_son(node, link));
  else if (node->type == S_PIPE)
    return (exec_cmd_pipe(node, link));
  return (FALSE);
}

extern int	exec_pipe_cmd(t_node *node, t_link *link)
{
  int		pid;
  int		pipe_fd[2];
  int		return_value[2];

  if (pipe(pipe_fd) == -1)
    return (FALSE);
  pid = -1;
  if ((pid = fork()) == -1)
    return (FALSE);
  if (pid == 0)
    {
      if (close(pipe_fd[0]) == -1 || dup2(pipe_fd[1], 1) == -1)
	return (FALSE);
      return_value[0] = exec_son(node->left, link);
    }
  else
    {
      wait(&pid);
      if (check_return(pid) == FALSE)
	  return (FALSE);
      return_value[1] = exec_father(node->right, link, pipe_fd);
    }
  if (return_value[0] == TRUE && return_value[1] == TRUE)
    return (TRUE);
  return (FALSE);
}

extern int	exec_pipe_built(t_node *node, t_link *link)
{
  int		pid;
  int		pipe_fd[2];
  int		return_value[2] = {TRUE, TRUE};

  if (pipe(pipe_fd) == -1)
    return (FALSE);
  pid = -1;
  if ((pid = vfork()) == -1)
    return (FALSE);
  if (pid == 0)
    {
      if (close(pipe_fd[0]) == -1 || dup2(pipe_fd[1], 1) == -1)
	return (FALSE);
      return_value[0] = exec_son(node->left, link);
    }
  else
    {
      return_value[1] = exec_father(node->right, link, pipe_fd);
      if (wait(&pid) == -1)
	return (FALSE);
    }
  if (return_value[0] == TRUE && return_value[1] == TRUE)
    return (TRUE);
  return (FALSE);
}

extern int	exec_pipe(t_node *node, t_link *link)
{
  char		**cmd;
  t_built	*built;

  if ((cmd = edit_command(link, node->left->word)) != NULL)
    {
      if ((built = is_built(cmd[0], link)) != NULL)
	return (exec_pipe_built(node, link));
      else
	return (exec_pipe_cmd(node, link));
    }
  return (TRUE);
}

extern int	exec_cmd_pipe(t_node *node, t_link *link)
{
  int		pid;
  int		ret;

  ret = TRUE;
  if (node->left == NULL || node->right == NULL)
    return (FALSE);
  if (node->parent != NULL &&  node->parent->type == S_PIPE)
    ret =  (exec_pipe(node, link));
  else if (node->parent == NULL || node->parent->type != S_PIPE)
    {
      pid = fork();
      if (pid == 0)
	ret = exec_pipe(node, link);
      else
	wait(&pid);
    }
  else
    return (FALSE);
  return (ret);
}
