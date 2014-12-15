/*
** get_pwd.c for get_pwd in /home/bodart/projets/Tek1/42sh
** 
** Made by BODART Louis
** Login   <bodart@bodart-l-pc>
** 
** Started on  Mon May 20 11:49:41 2013 BODART Louis
** Last update Sun May 26 00:02:28 2013 BODART Louis
*/

#include	<unistd.h>
#include	<stdlib.h>

char		*get_pwd()
{
  char		*str;
  int		i;

  i = 1;
  str = NULL;
  while (str == NULL)
    {
      if ((str = getcwd(str, i)) == NULL)
	free(str);
      i++;
    }
  return (str);
}
