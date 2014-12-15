/*
** parse_env.c for parse_env in /home/telenc_r/rendu/42sh/my/exec
** 
** Made by telenc_r
** Login   <telenc_r@telenc>
** 
** Started on  Thu May 16 15:11:29 2013 telenc_r
** Last update Thu May 23 17:48:41 2013 martre_s
*/

#include	<unistd.h>
#include	"parser.h"
#include	"lib.h"
#include	"types.h"

extern t_env   	*get_line_env(char *str, t_link *link)
{
  t_env		*tmp;

  tmp = link->env;
  while (tmp != NULL)
    {
      if (my_strcmp(tmp->name, str) == 0)
	return (tmp);
      tmp = tmp->nxt;
    }
  return (NULL);
}
