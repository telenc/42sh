/*
** key_delete.c for key_delete in /home/telenc_r/rendu/42sh/42sh-2017-bodart_l/term42
** 
** Made by telenc_r
** Login   <telenc_r@telenc>
** 
** Started on  Fri May 24 09:04:59 2013 telenc_r
** Last update Fri May 24 09:08:07 2013 telenc_r
*/

#include	"parser.h"

int		key_delete(t_link *link)
{
  link->line = delete_char_line(link->line);
  del_one();
  my_show_list(link->line, link);
  return (TRUE);
}
