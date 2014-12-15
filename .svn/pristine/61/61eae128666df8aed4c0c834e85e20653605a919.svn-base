/*
** key_enter.c for key_enter in /home/telenc_r/rendu/42sh/42sh-2017-bodart_l/term42
** 
** Made by telenc_r
** Login   <telenc_r@telenc>
** 
** Started on  Fri May 24 09:06:21 2013 telenc_r
** Last update Sun May 26 16:15:12 2013 telenc_r
*/

#include	<unistd.h>
#include	"parser.h"
#include	"lib.h"

int		key_enterr(t_link *link)
{
  if (link->line != NULL)
    {
      my_putchar('\n');
      get_command_line(link, convert_list_to_str(link->line), 1);
      link->line = NULL;
      if (link->exit_status == 0 && link->term_caps == 1)
	display_prompt(link);
    }
  else
    {
      my_putchar('\n');
      display_prompt(link);
    }
  sauv_cur();
  return (TRUE);
}
