/*
** source.c for source in /home/telenc_r/rendu/42sh/42sh-2017-bodart_l
** 
** Made by telenc_r
** Login   <telenc_r@telenc>
** 
** Started on  Sun May 26 14:21:02 2013 telenc_r
** Last update Sun May 26 17:15:46 2013 telenc_r
*/

#include	<stdio.h>
#include	"parser.h"

int		builtin_source(t_link *link, char **cmd)
{
  if (cmd[0] && !cmd[1])
    {
      fprintf(stderr, "dtsh: source: filename argument required\n");
      fprintf(stderr, "source: usage: source <filename>\n");
    }
  else if (cmd[0] && cmd[1])
    return (take_my_bashrc(link, cmd[1]));
  return (FALSE);
}
