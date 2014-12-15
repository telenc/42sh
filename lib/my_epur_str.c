/*
** my_epur_str.c for my_epur_str in /home/bodart/projets/Tek1/42sh
** 
** Made by louis bodart
** Login   <bodart_l@epitech.net>
** 
** Started on  Mon May 13 13:55:53 2013 BODART Louis
** Last update Sat May 25 22:31:18 2013 BODART Louis
*/

#include	"lib.h"

int		words_after(char *str, int pos)
{
  while (str[pos] && str[pos] < 33)
    pos++;
  if (!str[pos])
    return (0);
  return (1);
}

int		remove_first_spaces(char *str)
{
  int		i;

  i = 0;
  while (str[i] && str[i] < 33)
    i++;
  return (i);
}

char		*my_epur_str(char *str)
{
  int		i;
  int		j;
  char		*new_str;

  j = 0;
  i = remove_first_spaces(str);
  if ((new_str = my_malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  new_str = my_memset(new_str, 0, (my_strlen(str) + 1));
  while (str[i])
    {
      if (str[i] < 33)
	while (str[i + 1] && str[i + 1] < 33)
	  i++;
      if (words_after(str, i))
	{
	  if (str[i] > 32 || str[i] == ' ')
	    new_str[j++] = str[i];
	  else
	    new_str[j++] = ' ';
	}
      if (str[i])
	i++;
    }
  return (new_str);
}
