/*
** my_strncut.c for my_strncut in /home/bodart/projets/Tek1/verifsvn
** 
** Made by louis bodart
** Login   <bodart_l@epitech.net>
** 
** Started on Mon Feb 25 14:16:17 2013 louis bodart
** Last update Sat May 25 22:59:34 2013 BODART Louis
*/

#include	<stdlib.h>
#include	"lib.h"

char		*my_strncut(char *str, int start, int stop)
{
  char		*new_str;
  int		i;
  int		j;

  i = 0;
  j = 0;
  if (!(new_str = my_malloc(sizeof(char) * (my_strlen(str) + 1))))
    return (NULL);
  new_str = my_memset(new_str, 0, my_strlen(str) + 1);
  while (i < start)
    i++;
  while (str[i] && i < stop)
    new_str[j++] = str[i++];
  return (new_str);
}
