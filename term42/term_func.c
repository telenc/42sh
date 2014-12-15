/*
** term_func.c for term_func in /home/telenc_r/rendu/42sh/42sh-2017-bodart_l/term42
** 
** Made by telenc_r
** Login   <telenc_r@telenc>
** 
** Started on  Sun May 26 13:29:19 2013 telenc_r
** Last update Sun May 26 13:31:40 2013 telenc_r
*/

#include	<termios.h>
#include	<stdlib.h>
#include	<curses.h>
#include	<term.h>
#include	"lib.h"
#include	"parser.h"

void		move_right(t_link *link)
{
  char		*clean;

  clean = tgetstr("nd", NULL);
  if (change_selected_right(link) == TRUE)
    tputs(clean, 1, my_putchar_int);
}

void		del_one()
{
  char		*clean;

  clean = tgetstr("rc", NULL);
  tputs(clean, 1, my_putchar_int);
  clean = tgetstr("cd", NULL);
  tputs(clean, 1, my_putchar_int);
}

void		my_clean()
{
  char		*clean;

  clean = tgetstr("cl", NULL);
  tputs(clean, 1, my_putchar_int);
}

void		move_left(t_link *link)
{
  if (change_selected_left(link) == TRUE)
    move_cur_left();
}

void		move_cur_left()
{
  char		*clean;

  clean = tgetstr("le", NULL);
  tputs(clean, 1, my_putchar_int);
}
