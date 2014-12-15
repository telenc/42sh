/*
** my_explode_str.c for my_explode_str in /home/bodart/projets/Tek1/verifsvn
** 
** Made by louis bodart
** Login   <bodart_l@epitech.net>
** 
** Started on Fri Mar  8 14:22:05 2013 louis bodart
** Last update Sat May 25 22:51:38 2013 BODART Louis
*/

#include	<stdlib.h>
#include	"lib.h"

static int	count_words_str(char *str, char *sep)
{
  int		words;
  int		str_pos;
  int		sep_pos;

  words = 0;
  str_pos = 0;
  sep_pos = 0;
  while (str[str_pos])
    {
      if (str[str_pos] == sep[sep_pos])
	sep_pos++;
      else
	sep_pos = 0;
      if (sep_pos == my_strlen(sep))
	{
	  sep_pos = 0;
	  words++;
	}
      str_pos++;
    }
  return (words + 1);
}

static int	is_separator(char *str, int i, char *sep)
{
  int		j;

  j = 0;
  while (str[i] && j < my_strlen(sep))
    if (str[i++] != sep[j++])
      return (0);
  return (1);
}

char		**my_explode_str(char *str, char *sep)
{
  int		cursor_str;
  int		cursor_tab;
  int		cursor_tab_str;
  char		**tab;

  cursor_str = 0;
  cursor_tab = 0;
  if (!(tab = my_malloc(sizeof(char *) * (count_words_str(str, sep) + 1))))
    return (NULL);
  while (str[cursor_str])
    {
      cursor_tab_str = 0;
      tab[cursor_tab] = my_malloc(sizeof(char) * (my_strlen(str) + 1));
      if (tab[cursor_tab])
	{
	  tab[cursor_tab] = my_memset(tab[cursor_tab], 0, (my_strlen(str) + 1));
	  while (str[cursor_str] && !is_separator(str, cursor_str, sep))
	    tab[cursor_tab][cursor_tab_str++] = str[cursor_str++];
	}
      if (str[cursor_str])
	cursor_str += my_strlen(sep);
      cursor_tab++;
    }
  tab[cursor_tab] = NULL;
  return (tab);
}
