/*
** display_prompt.c for display_prompt in /home/telenc_r/rendu/42sh/42sh-2017-bodart_l/term42
** 
** Made by telenc_r
** Login   <telenc_r@telenc>
** 
** Started on  Fri May 24 09:20:14 2013 telenc_r
** Last update Sun May 26 16:41:26 2013 BODART Louis
*/

#include	"parser.h"

void		display_prompt(t_link *link)
{
  char		*prompt;

  if ((prompt = get_local_value(link, "PS1")))
    {
      my_printf("%s", prompt);
    }
  else
    my_printf("dtsh1.0 > ");
}
