/*
** key_tab.c for key_tab in /home/telenc_r/rendu/42sh/42sh-2017-bodart_l/term42
** 
** Made by telenc_r
** Login   <telenc_r@telenc>
** 
** Started on  Fri May 24 09:09:47 2013 telenc_r
** Last update Sun May 26 14:12:03 2013 telenc_r
*/

#include	<unistd.h>
#include	"parser.h"

int		key_tab(t_link *link)
{
  if (link->line != NULL)
    {
      if (term_auto_completion(link) == FALSE)
	{
	  display_prompt(link);
	  sauv_cur();
	  my_show_list(link->line, link);
	}
      else
	{
	  del_one();
	  my_show_list(link->line, link);
	}
    }
  return (TRUE);
}
