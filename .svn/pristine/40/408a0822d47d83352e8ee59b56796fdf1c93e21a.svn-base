/*
** my_explode_cote.c for my_explode_cote in /home/telenc_r/rendu/42sh/my
** 
** Made by telenc_r
** Login   <telenc_r@telenc>
** 
** Started on  Tue May 21 16:06:17 2013 telenc_r
** Last update Sun May 26 17:35:10 2013 telenc_r
*/

#include	<stdlib.h>
#include	"lib.h"

static	int	count_words_cote(char *str, int c)
{
  int		words;
  int		i;

  words = 0;
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i++] == c)
	words++;
      if (str[i] == '\'')
	while (str[i] != '\0' && str[i] != '\'')
	  i++;
      if (str[i] == '"')
	while (str[i] != '\0' && str[i] != '"')
	  i++;
    }
  return (words + 1);
}

static char	*explode_str(char *str, char *tab,
			int *cursor_str, int *cursor_tab_str)
{
  char		c;

  while (str[*cursor_str] != ' ' && str[*cursor_str] != '\0')
    {
      c = str[*cursor_str];
      if (c == '\'' || c == '"')
	{
	  tab[(*cursor_tab_str)++] = str[(*cursor_str)++];
	  while (str[*cursor_str] != '\0' && str[*cursor_str] != c)
	    tab[(*cursor_tab_str)++] = str[(*cursor_str)++];
	  tab[(*cursor_tab_str)++] = str[(*cursor_str)++];
	}
      else
	tab[(*cursor_tab_str)++] = str[(*cursor_str)++];
    }
  tab[*cursor_tab_str] = '\0';
  return (tab);
}

char		**my_explode_cote(char *str, int c)
{
  char		**tab;
  int		cursor_tab;
  int		cursor_str;
  int		cursor_tab_str;

  if (!(tab = my_malloc(sizeof(char *) * (count_words_cote(str, c) + 1))))
    return (NULL);
  cursor_tab = 0;
  cursor_str = 0;
  while (cursor_tab < count_words_cote(str, c))
    {
      cursor_tab_str = 0;
      tab[cursor_tab] = my_malloc(sizeof(char) * (my_strlen(str) + 1));
      if (tab[cursor_tab])
	tab[cursor_tab] = explode_str(str, tab[cursor_tab],
				&cursor_str, &cursor_tab_str);
      if (str[cursor_str] != '\0')
	cursor_str++;
      cursor_tab++;
    }
  tab[cursor_tab] = NULL;
  return (tab);
}
