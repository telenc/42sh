/*
** man.c for man in /home/telenc_r/rendu/42sh/42sh-2017-bodart_l
** 
** Made by telenc_r
** Login   <telenc_r@telenc>
** 
** Started on  Sun May 26 17:06:44 2013 telenc_r
** Last update Sun May 26 17:09:37 2013 telenc_r
*/

#include	"parser.h"
#include	"lib.h"

int		builtin_man(t_link *link, char **cmd)
{
  (void)cmd;
  get_command_line(link, my_strdup("cat < .man42sh | less"), 0);
  return (TRUE);
}
