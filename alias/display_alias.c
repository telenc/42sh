/*
** display_alias.c for display_alias in /home/telenc_r/rendu/42sh/42sh-2017-bodart_l
** 
** Made by telenc_r
** Login   <telenc_r@telenc>
** 
** Started on  Tue May 21 15:36:00 2013 telenc_r
** Last update Tue May 21 19:45:19 2013 telenc_r
*/

#include	<unistd.h>
#include	"parser.h"
#include	"alias.h"

extern void	display_alias(t_alias *list)
{
  t_alias	*tmp;

  tmp = list;
  while (tmp != NULL)
    {
      my_printf("alias %s=%s\n", tmp->alias, tmp->cmd);
      tmp = tmp->nxt;
    }
}
