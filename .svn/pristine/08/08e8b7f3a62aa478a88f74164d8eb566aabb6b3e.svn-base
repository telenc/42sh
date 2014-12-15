/*
** my_echo.c for 42sh in /home/alice/Promo_2017/Teck_1/Projets/SystemUnix/42sh
** 
** Made by alice groux
** Login   <groux_a@epitech.net>
** 
** Started on  Wed Apr 17 10:45:42 2013 alice groux
** Last update Sun May 26 17:40:10 2013 telenc_r
*/

#include	<stdio.h>
#include	"parser.h"
#include	"lib.h"

void		my_putstr_space(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i++;
    }
  my_putchar(' ');
}

int		builtin_echo(t_link *link, char **cmd)
{
  int		i;

  (void)link;
  if (cmd[1])
    {
      if (my_strcmp("-n", cmd[1]) == 0)
	{
	  i = 2;
	  while (cmd[i])
	    my_putstr_space(check_quote(cmd[i++]));
	}
      else
	{
	  i = 1;
	  while (cmd[i])
	    my_putstr_space(check_quote(cmd[i++]));
	  my_putchar('\n');
	}
    }
  else
    my_putchar('\n');
  return (TRUE);
}

