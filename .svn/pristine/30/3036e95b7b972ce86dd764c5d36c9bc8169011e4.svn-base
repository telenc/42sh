/*
** line_syntax.c for line_syntax in /home/bodart/projets/Tek1/42sh
** 
** Made by BODART Louis
** Login   <bodart@bodart-l-pc>
** 
** Started on  Sat May 25 13:53:38 2013 BODART Louis
** Last update Sun May 26 19:13:37 2013 BODART Louis
*/

#include	"parser.h"

int		syntax_is_right(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (str[i] < 32 || str[i] > 126)
	{
	  my_printf("%s\n", str);
	  return (FALSE);
	}
      i++;
    }
  return (TRUE);
}
