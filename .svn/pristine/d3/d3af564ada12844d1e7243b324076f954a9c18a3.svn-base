/*
** line_parser.c for line_parser in /home/bodart/projets/Tek1/42sh
** 
** Made by BODART Louis
** Login   <bodart@bodart-l-pc>
** 
** Started on  Mon May 13 11:59:20 2013 BODART Louis
** Last update Sun May 26 16:45:45 2013 telenc_r
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	"types.h"
#include	"parser.h"
#include	"lib.h"

int		check_line_syntax(t_lex *lex)
{
  t_lex		*tmp;

  tmp = lex;
  while (tmp != NULL)
    {
      if (tmp->type == UNKNOWN)
	return (1);
      if (compare_with_grammar(tmp) == FALSE)
	{
	  fprintf(stderr, "dtsh: syntax error near unexpected token `%s'\n",
		  tmp->word);
	  return (1);
	}
      tmp = tmp->nxt;
    }
  return (0);
}

int		epur_commands(t_lex *lex)
{
  t_lex		*tmp;
  char		*tmp_word;

  tmp = lex;
  while (tmp != NULL)
    {
      if (tmp->type == COMMAND)
	{
	  tmp_word = my_epur_str(tmp->word);
	  free(tmp->word);
	  tmp->word = tmp_word;
	}
      tmp = tmp->nxt;
    }
  return (TRUE);
}

extern t_node	*create_node_by_lex(t_lex *lex)
{
  t_node	*new;

  if (!(new = my_malloc(sizeof(t_node))))
    return (NULL);
  new->type = lex->type;
  new->word = my_strdup(lex->word);
  new->left = NULL;
  new->right = NULL;
  new->parent = NULL;
  return (new);
}
