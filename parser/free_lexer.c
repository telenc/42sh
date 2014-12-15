/*
** free_lexer.c for free_lexer in /home/bodart/projets/Tek1/42sh/42sh-2017-bodart_l
** 
** Made by BODART Louis
** Login   <bodart@bodart-l-pc>
** 
** Started on  Sun May 26 16:02:25 2013 BODART Louis
** Last update Sun May 26 16:04:45 2013 BODART Louis
*/

#include	<stdlib.h>
#include	"parser.h"

void		free_lexer(t_lex *lex)
{
  t_lex		*ptr;
  t_lex		*tmp;

  tmp = lex;
  while (tmp != NULL)
    {
      ptr = tmp;
      tmp = tmp->nxt;
      free(ptr);
    }
}
