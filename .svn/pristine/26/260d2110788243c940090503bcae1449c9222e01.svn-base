/*
** explode.c for explode in /home/telenc_r/rendu/42sh/42sh-2017-bodart_l/parser
** 
** Made by telenc_r
** Login   <telenc_r@telenc>
** 
** Started on  Sun May 26 13:46:05 2013 telenc_r
** Last update Sun May 26 13:47:31 2013 telenc_r
*/

#include	"parser.h"

extern char	**replace_cmd(char **cmd, t_link *link)
{
  int		i;

  i = 0;
  while (cmd[i])
    {
      if (is_redir(cmd[i]) ==  TRUE)
	return (cmd);
      if (cmd[i][0] && cmd[i][0] == '!')
	cmd[i] = exec_exclamation(cmd[i], link->histo);
      if (contain(cmd[i], '*') == TRUE || contain(cmd[i], '?') == TRUE)
	cmd[i] = glob_exec(cmd[i]);
      i++;
    }
  return (cmd);
}
