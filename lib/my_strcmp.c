/*
** my_strcmp.c for my_strcmp in /home/bodart/projets/Tek1/minishell1/lib
** 
** Made by louis bodart
** Login   <bodart_l@epitech.net>
** 
** Started on Mon Dec 17 18:08:36 2012 louis bodart
** Last update Sat May 25 21:35:38 2013 BODART Louis
*/

#include	"lib.h"

int		my_strcmp(char *str_1, char *str_2)
{
  int		i;

  i = 0;
  if (!str_1 || !str_2)
    return (1);
  if (my_strlen(str_1) != my_strlen(str_2))
    return (1);
  while (str_1[i] != '\0')
    {
      if (str_1[i] != str_2[i])
	return (1);
      i++;
    }
  return (0);
}

int		my_strncmp(char *s1, char *s2, int n)
{
  int		i;

  i = 1;
  while (*s1 == *s2 && (*s1 || *s2) && i < n)
    {
      s1++;
      s2++;
      i++;
    }
  return (*s1 - *s2);
}
