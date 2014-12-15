/*
** exec_one_cmd.c for exec_one_cmd in /home/telenc_r/rendu/42sh/my/exec
** 
** Made by telenc_r
** Login   <telenc_r@telenc>
** 
** Started on  Thu May 16 15:01:54 2013 telenc_r
** Last update Sun May 26 19:59:14 2013 telenc_r
*/

#define		_BSD_SOURCE
#include	<sys/types.h>
#include	<unistd.h>
#include	<sys/wait.h>
#include	<stdio.h>
#include	"parser.h"
#include	"types.h"
#include	"lib.h"

static int	exec_one_built(t_link *link, char **cmd, t_built *built)
{
  int		fork_return;

  if ((fork_return = vfork()) == 0)
    {
      if (redir_right(&cmd) == FALSE || redir_left(&cmd) == FALSE)
	_exit(FALSE);
      _exit(built->function(link, remove_all_quote(cmd)));
    }
  else
    {
      if (my_strcmp(built->name, "cd") == 0)
	if (get_var_value(link, "PWD"))
	  chdir(get_var_value(link, "PWD"));
      wait(&fork_return);
    }
  return (TRUE);
}

extern int	check_return(int fork_return)
{
  if (WCOREDUMP(fork_return) != 0)
    {
      fprintf(stderr, "Segmentation fault (core dumped)\n");
      return (FALSE);
    }
  if (WIFEXITED(fork_return) == 0)
    {
      return (FALSE);
    }
  if (WEXITSTATUS(fork_return) != 0)
    {
      my_printf("On renvoie FALSE\n");
      return (FALSE);
    }
  return (TRUE);
}

static int	exec_one_comd(t_link *link, char **cmd, char **env)
{
  int		fork_return;

  if (link->term_caps)
    finish_term(link);
  if ((fork_return = fork()) == 0)
    {
      if (redir_right(&cmd) == FALSE || redir_left(&cmd) == FALSE)
	_exit(FALSE);
      execve(cmd[0], remove_all_quote(cmd), env);
    }
  else
    {
      wait(&fork_return);
      if (link->term_caps == 0)
	term_init(link, env);
      if (check_return(fork_return) == FALSE)
	  return (FALSE);
   }
  return (TRUE);
}

extern int	exec_one_cmd(t_node *node, t_link *link)
{
  char		**cmd;
  char		**env;
  t_built	*built;

  cmd = edit_command(link, node->word);
  if (cmd != NULL && (built = is_built(cmd[0], link)) != NULL)
    return (exec_one_built(link, cmd, built));
  else if (cmd != NULL && (env = convert_environment(link->env)))
    return (exec_one_comd(link, cmd, env));
  else
    {
      my_printf("%s : Command not found\n", node->word);
      return (FALSE);
    }
  return (TRUE);
}
