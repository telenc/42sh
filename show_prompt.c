/*
** show_prompt.c for show_prompt in /home/bodart/projets/Tek1/42sh
** 
** Made by BODART Louis
** Login   <bodart@bodart-l-pc>
** 
** Started on  Sat May  4 14:50:40 2013 BODART Louis
** Last update Sun May 26 17:00:20 2013 telenc_r
*/

#include	<stdlib.h>
#include	"parser.h"
#include	"get_next_line.h"
#include	"lib.h"
#include	"completion.h"

int		get_command_line(t_link *link, char *input, int myrc)
{
  t_lex		*lex;

  reset_histo(link);
  if (syntax_is_right(input) == FALSE)
    return (FALSE);
  input = pre_lexer(link, input, myrc);
  if (input != NULL)
    {
      lex = line_lexer(input);
      if (check_line_syntax(lex) == 1)
	  return (FALSE);
      epur_commands(lex);
    }
  else
    lex = NULL;
  if (check_line_syntax(lex) == 1)
      return (FALSE);
  input = concat_lexeme(lex);
  link->trees = build_trees(lex);
  while (link->trees)
    exec(link->trees, link);
  return (TRUE);
}

int		show_prompt(t_link *link)
{
  char		*input;

  display_prompt(link);
  while ((input = get_next_line(0)))
    {
      get_command_line(link, input, 1);
      if (link->exit_status)
	return (TRUE);
      display_prompt(link);
      free(input);
    }
  return (TRUE);
}
