/*
** glob.c for glob in /home/martre_s/Teck1/42
** 
** Made by martre_s
** Login   <martre_s@steven>
** 
** Started on  Wed May 22 16:31:39 2013 martre_s
** Last update Wed May 22 18:37:29 2013 telenc_r
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<glob.h>
#include	"lib.h"

char		*glob_exec(char *str)
{
  glob_t	globbuf;
  int		i;
  char		*tmp;

  i = glob(str, GLOB_TILDE, NULL, &globbuf);
  if (i != 0)
    return (str);
  i = 0;
  while (globbuf.gl_pathv[i])
    {
      if (i == 0)
	tmp = my_strdup(globbuf.gl_pathv[i]);
      else
	tmp = my_strcat(tmp, my_strcat(" ", globbuf.gl_pathv[i]));
      i++;
    }
  return (tmp);
}

