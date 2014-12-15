/*
** error.c for  in /home/ballen_d//mysh
** 
** Made by damien ballenghien
** Login   <ballen_d@epitech.net>
** 
** Started on  Wed Dec 12 13:07:49 2012 damien ballenghien
** Last update Sun May 26 01:15:57 2013 telenc_r
*/

#include	<stdlib.h>
#include	"lib.h"

char		*envir(char **envp)
{
  char		*path;
  int		j;
  int		i;

  i = 5;
  j = 0;
  while (envp[j] != NULL)
    {
      if (my_strncmp(envp[j], "TERM=", 5) == 0)
	{
	  if (!(path = my_malloc((my_strlen(envp[j]) + 1) * sizeof(char))))
	    return (NULL);
	  while (envp[j][i] != '\0')
	    {
	      path[i - 5] = envp[j][i];
	      i++;
	    }
	  path[i] = '\0';
	  return (path);
	}
      j++;
    }
  return (NULL);
}
