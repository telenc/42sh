/*
** exec.c for exec in /home/telenc_r/rendu/42sh/my/exec
** 
** Made by telenc_r
** Login   <telenc_r@telenc>
** 
** Started on  Thu May 16 14:50:55 2013 telenc_r
** Last update Sun May 26 19:02:21 2013 telenc_r
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"parser.h"
#include	"types.h"

extern int	exec_son(t_node *node, t_link *link)
{
  char		**cmd;
  t_built	*built;

  cmd = edit_command(link, node->word);
  if (cmd != NULL && (built = is_built(cmd[0], link)) != NULL)
    {
      if (redir_right(&cmd) == FALSE || redir_left(&cmd) == FALSE)
	_exit(FALSE);
      _exit(built->function(link, remove_all_quote(cmd)));
    }
  else if (cmd != NULL)
    {
      if (redir_right(&cmd) == FALSE || redir_left(&cmd) == FALSE)
	_exit(FALSE);
      execve(cmd[0], remove_all_quote(cmd), convert_environment(link->env));
      return (TRUE);
    }
  else
    {
      my_printf("%s: Command not found\n", node->word);
      _exit(0);
    }
  free(node);
  return (FALSE);
}

extern int	exec(t_trees *tree, t_link *link)
{
  link->trees = link->trees->nxt;
  if (tree->root != NULL)
    return (exec_cmd_type(tree->root, link));
  return (TRUE);
}

extern int	exec_cmd_type(t_node *node, t_link *link)
{
  int		res;

  res = FALSE;
  if (node->type == S_AND)
    res = exec_cmd_and(node, link);
  else if (node->type == S_OR)
    res = exec_cmd_or(node, link);
  else if (node->type == S_PIPE)
    res = exec_cmd_pipe(node, link);
  else if (node->type == COMMAND)
    res = exec_one_cmd(node, link);
  free(node);
  return (res);
}
