/*
** my_putstr.c for my_putstr in /home/bodart/projets/SRC
** 
** Made by louis bodart
** Login   <bodart_l@epitech.net>
** 
** Started on Thu Nov 22 17:02:33 2012 louis bodart
** Last update Sun May 26 14:14:35 2013 BODART Louis
*/

#include	<unistd.h>
#include	<stdlib.h>

void		my_putchar(unsigned char c)
{
  write(1, &c, 1);
}

void		my_putstr(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    my_putchar(str[i++]);
}
