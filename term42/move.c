/*
** fonctions.c for fonctions in /home/lyto/my_select
** 
** Made by lyto
** Login   <lyto@lyto>
** 
** Started on  Fri Jan 18 14:19:27 2013 lyto
** Last update Sun May 26 13:44:09 2013 telenc_r
*/

#include	<termios.h>
#include	<stdlib.h>
#include	<curses.h>
#include	<term.h>
#include	"lib.h"
#include	"parser.h"

int		my_putchar_int(int c)
{
  my_putchar((char)c);
  return (TRUE);
}

void		my_clear()
{
  char		*clear;

  clear = tgetstr("cd", NULL);
  tputs(clear, 1, my_putchar_int);
}

void		my_delete_line()
{
  char		*clean;

  clean = tgetstr("dl", NULL);
  tputs(clean, 1, my_putchar_int);
}

void		sauv_cur()
{
  char		*clean;

  clean = tgetstr("sc", NULL);
  tputs(clean, 1, my_putchar_int);
}
