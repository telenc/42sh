/*
** key_other.c for key_other in /home/telenc_r/rendu/42sh/42sh-2017-bodart_l/term42
** 
** Made by telenc_r
** Login   <telenc_r@telenc>
** 
** Started on  Fri May 24 09:11:39 2013 telenc_r
** Last update Sat May 25 16:17:08 2013 telenc_r
*/

#include	"parser.h"

int		key_other(t_link *link, unsigned char buff[5])
{
  if (buff[0] >= 32 && buff[1] == 0)
    {
      link->line = put_in_list(link->line, buff[0]);
      del_one();
      my_show_list(link->line, link);
    }
  return (TRUE);
}
