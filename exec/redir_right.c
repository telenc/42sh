/*
** redir_right.c for redir_right in /home/telenc_r/rendu/42sh/42sh-2017-bodart_l/exec
** 
** Made by telenc_r
** Login   <telenc_r@telenc>
** 
** Started on  Sun May 26 10:46:21 2013 telenc_r
** Last update Sun May 26 10:49:10 2013 telenc_r
*/

#include	<unistd.h>
#include	"parser.h"
#include	"lib.h"

extern int	get_next_redir_right(char **cmd, int pos)
{
  while (cmd[pos] != NULL)
    {
      if (my_strcmp(cmd[pos], ">>") == 0)
	return (pos);
      if (my_strcmp(cmd[pos], ">") == 0)
	return (pos);
      pos++;
    }
  return (-1);
}

