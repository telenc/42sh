/*
** concatenation.c for concatenation in /home/bodart/projets/Tek1/42sh
** 
** Made by BODART Louis
** Login   <bodart@bodart-l-pc>
** 
** Started on  Sun May 19 15:18:31 2013 BODART Louis
** Last update Sat May 25 15:14:22 2013 telenc_r
*/

#include	<stdlib.h>
#include	"parser.h"
#include	"types.h"
#include	"lib.h"

extern int	contain(char *str, char c)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    if (str[i++] == c)
      return (TRUE);
  return (FALSE);
}

char		*concat_tab(char **cmd)
{
  char		*tmp;
  char		*ptr;
  int		i;

  i = 0;
  if (cmd[i] == NULL)
    return (my_strdup(""));
  if (cmd[i + 1])
    tmp = my_strcat(cmd[i], " ");
  else
    return (my_strdup(cmd[i]));
  i++;
  while (cmd[i])
    {
      if (cmd[i + 1])
	{
	  ptr = my_strcat(cmd[i], " ");
	  tmp = my_strcat(tmp, ptr);
	}
      else
	tmp = my_strcat(tmp, cmd[i]);
      i++;
    }
  return (tmp);
}

char		*concat_lexeme(t_lex *lex)
{
  char		*tmp;
  char		*ptr;

  if (lex == NULL)
    return (NULL);
  if (lex->nxt)
    tmp = my_strcat(lex->word, " ");
  else
    return (my_strdup(lex->word));
  lex = lex->nxt;
  while (lex)
    {
      if (lex->nxt)
	{
	  ptr = my_strcat(lex->word, " ");
	  tmp = my_strcat(tmp, ptr);
	}
      else
	tmp = my_strcat(tmp, lex->word);
      lex = lex->nxt;
    }
  return (tmp);
}
