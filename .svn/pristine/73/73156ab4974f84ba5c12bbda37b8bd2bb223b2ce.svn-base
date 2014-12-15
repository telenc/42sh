/*
** built.c for built in /home/telenc_r/rendu/42sh/my/exec
** 
** Made by telenc_r
** Login   <telenc_r@telenc>
** 
** Started on  Tue May 21 13:26:28 2013 telenc_r
** Last update Thu May 23 16:53:25 2013 martre_s
*/

#include	<unistd.h>
#include	"lib.h"
#include	"parser.h"

extern t_built	*is_built(char *cmd, t_link *link)
{
  t_built	*tmp;

  tmp = link->built;
  while (tmp != NULL)
    {
      if (my_strcmp(tmp->name, cmd) == 0)
	return (tmp);
      tmp = tmp->nxt;
    }
  return (NULL);
}
