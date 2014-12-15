/*
** key_arrow.c for key_arrow in /home/telenc_r/rendu/42sh/42sh-2017-bodart_l/term42
** 
** Made by telenc_r
** Login   <telenc_r@telenc>
** 
** Started on  Fri May 24 09:08:13 2013 telenc_r
** Last update Fri May 24 12:27:06 2013 martre_s
*/

#include	<unistd.h>
#include	"parser.h"

int		key_arrow_up(t_link *link)
{
  if (link->histo == NULL)
    return (FALSE);
  link->line = convert_str_to_list(up_histo(link));
  del_one();
  my_show_list(link->line, link);
  return (TRUE);
}

int		key_arrow_down(t_link *link)
{
  if (link->histo == NULL)
    return (FALSE);
  link->line = convert_str_to_list(down_histo(link));
  del_one();
  my_show_list(link->line, link);
  return (TRUE);
}

