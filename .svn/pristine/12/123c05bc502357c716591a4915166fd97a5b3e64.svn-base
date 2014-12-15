/*
** shell_grammar.c for shell_grammar in /home/bodart/projets/Tek1/42sh
** 
** Made by BODART Louis
** Login   <bodart@bodart-l-pc>
** 
** Started on  Mon May 13 12:04:24 2013 BODART Louis
** Last update Sun May 26 19:14:24 2013 telenc_r
*/

#include	<stdlib.h>
#include	"types.h"
#include	"parser.h"
#include	"lib.h"

int		after_separator(t_lex *tmp)
{
  if (tmp->nxt != NULL)
    if (tmp->nxt->type != COMMAND && tmp->nxt->type != UNKNOWN)
      return (1);
  return (0);
}

int		compare_with_grammar(t_lex *tmp)
{
  if (tmp->type == COMMAND)
    {
      if (tmp->nxt != NULL && tmp->nxt->type == COMMAND)
	return (FALSE);
    }
  else
    {
      if (tmp->prv == NULL && tmp->type != S_SEMICOLON)
	return (FALSE);
      if (tmp->prv != NULL && tmp->prv->type != COMMAND)
	return (FALSE);
      if (tmp->nxt == NULL && tmp->type != S_SEMICOLON)
	return (FALSE);
      if (tmp->nxt != NULL)
	if (tmp->prv != NULL && tmp->prv->type != COMMAND)
	  return (FALSE);
    }
  return (TRUE);
}

extern char	*concat_replace(char *result, char str)
{
  char		*sauv;
  char		*sauv_two;

  sauv = result;
  sauv_two = convert_char_to_str(str);
  result = my_strcat(result, sauv_two);
  free(sauv);
  free(sauv_two);
  return (result);
}
