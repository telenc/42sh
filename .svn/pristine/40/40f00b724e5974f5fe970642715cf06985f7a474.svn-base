/*
** my_malloc.c for my_malloc in /home/bodart/projets/Tek1/minishell1v2/lib
** 
** Made by louis bodart
** Login   <bodart_l@epitech.net>
** 
** Started on Sun Dec 30 12:55:51 2012 louis bodart
** Last update Sun May 26 16:16:39 2013 BODART Louis
*/

#include	<stdio.h>
#include	<stdlib.h>

void		*my_malloc(size_t size)
{
  void		*ptr;

  ptr = malloc(size);
  if (ptr == NULL)
    {
      fprintf(stderr, "Malloc failed\n");
      return (NULL);
    }
  return (ptr);
}

void		free_tab(char **tab)
{
  int		i;

  i = 0;
  while (tab[i])
    free(tab[i++]);
  free(tab);
}
