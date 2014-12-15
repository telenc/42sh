/*
** key_ctrl.c for key_ctrl in /home/telenc_r/rendu/42sh/42sh-2017-bodart_l
** 
** Made by telenc_r
** Login   <telenc_r@telenc>
** 
** Started on  Sun May 26 15:24:36 2013 telenc_r
** Last update Sun May 26 15:55:08 2013 telenc_r
*/

#include	<unistd.h>
#include	"parser.h"
#include	"my_term.h"
#include	"lib.h"
#include	"builtins.h"

int		key_all(t_link *link, unsigned char buff[10])
{
  if (CTRL_F)
    move_right(link);
  else if (CTRL_A)
    key_ctrl_a(link);
  else if (CTRL_U)
    key_ctrl_u(link);
  else if (CLEAR)
    key_clean(link);
  else if (CTRL_C)
    key_ctrl_c(link);
  else if (CTRL_D)
    key_ctrl_d(link);
  return (TRUE);
}

int		key_ctrl_a(t_link *link)
{
  while (get_selected(link->line) != link->line)
    {
      move_left(link);
    }
  return (1);
}

int		key_ctrl_u(t_link *link)
{
  while (get_selected(link->line) != link->line)
    {
      key_delete(link);
    }
  return (1);
}

int		key_ctrl_c(t_link *link)
{
  my_putstr("^C\n");
  display_prompt(link);
  sauv_cur();
  return (1);
}

int		key_ctrl_d(t_link *link)
{
  char		**cmd;

  cmd = my_malloc(sizeof(char *) * 1);
  cmd[0] = NULL;
  builtin_exit(link, cmd);
  return (1);
}
