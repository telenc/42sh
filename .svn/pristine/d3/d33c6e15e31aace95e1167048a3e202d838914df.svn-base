/*
** term.c for term in /home/telenc_r/rendu/42sh/my
** 
** Made by telenc_r
** Login   <telenc_r@telenc>
** 
** Started on  Wed May 22 11:36:40 2013 telenc_r
** Last update Sun May 26 16:14:33 2013 telenc_r
*/

#include	<sys/ioctl.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	"parser.h"
#include	"lib.h"
#include	"my_term.h"

int		manage_key(t_link *link)
{
  unsigned char	buff[10];
  int		fd;

  fd = read(0, buff, 9);
  buff[fd] = '\0';
  if ((DELETE) || (CTRL_H))
    key_delete(link);
  else if ((CTRL_F) || (CTRL_A) || (CTRL_U) || (CLEAR) || (CTRL_C) || (CTRL_D))
    key_all(link, buff);
  else if (ARROW_L)
    move_left(link);
  else if (ARROW_R)
    move_right(link);
  else if (ENTER)
    key_enterr(link);
  else if ((ARROW_U) || (CTRL_P))
    key_arrow_up(link);
  else if (ARROW_D)
    key_arrow_down(link);
  else if (TAB)
    key_tab(link);
  else
    key_other(link, buff);
  return (TRUE);
}

int		term_mode(t_link *link)
{
  display_prompt(link);
  sauv_cur();
  link->line = NULL;
  while (1)
    {
      if (link->term_caps == 0)
	return (4);
      if (manage_key(link) == FALSE)
	return (FALSE);
      if (link->exit_status)
	return (TRUE);
    }
  return (TRUE);
}
