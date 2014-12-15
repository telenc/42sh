/*
** line_lexer.c for line_lexer in /home/bodart/projets/Tek1/42sh/parser
** 
** Made by BODART Louis
** Login   <bodart@bodart-l-pc>
** 
** Started on  Mon May  6 14:11:59 2013 BODART Louis
** Last update Sun May 26 13:37:35 2013 telenc_r
*/

#include	<stdlib.h>
#include	"parser.h"
#include	"types.h"
#include	"lib.h"

extern t_lex	*add_lexeme(t_lex *lex, int type, char *word)
{
  t_lex		*new_lexeme;
  t_lex		*tmp;

  if (!(new_lexeme = my_malloc(sizeof(t_lex))))
    return (lex);
  new_lexeme->type = type;
  new_lexeme->word = my_strdup(word);
  new_lexeme->nxt = NULL;
  if (!lex)
    {
      new_lexeme->prv = NULL;
      return (new_lexeme);
    }
  tmp = lex;
  while (tmp->nxt)
    tmp = tmp->nxt;
  tmp->nxt = new_lexeme;
  new_lexeme->prv = tmp;
  return (lex);
}

extern int	lexeme_is_word(t_lex **lex, char *line,
			       char *str, int *i)
{
  int		j;
  char		c;

  j = 0;
  while (line[*i] && !is_separator(line[*i]))
    {
      if (((c = line[*i] == '"') &&
	   (*i != 0 && line[*i - 1] != '\\')) || (c = line[*i]) == '\'')
	{
	  str[j++] = line[(*i)++];
	  while (line[(*i)] != '\0' && line[(*i)] != c)
	    str[j++] = line[(*i)++];
	  if (line[(*i)] != '\0')
	    str[j++] = line[(*i)++];
	}
      if (line[(*i)] != '\0')
	str[j++] = line[(*i)++];
    }
  if (!my_count_printable(str))
    return (1);
  *lex = add_lexeme(*lex, COMMAND, str);
  return (0);
}

extern int	lexeme_is_separator(t_lex **lex, char *line,
				    char *str, int *i)
{
  int		separator_type;
  int		separator_char;
  int		j;

  j = 0;
  separator_char = line[*i];
  while (line[*i] && line[*i] == separator_char)
    str[j++] = line[(*i)++];
  separator_type = get_separator_type(str);
  *lex = add_lexeme(*lex, separator_type, str);
  return (0);
}

extern t_lex	*line_lexer(char *line)
{
  t_lex		*lex;
  char		*str;
  int		i;

  i = 0;
  lex = NULL;
  while (line[i])
    {
      if ((str = my_malloc(sizeof(char) * (my_strlen(line) + 1))))
	{
	  str = my_memset(str, 0, my_strlen(line) + 1);
	  if (!is_separator(line[i]))
	    lexeme_is_word(&lex, line, str, &i);
	  else
	    lexeme_is_separator(&lex, line, str, &i);
	  free(str);
	}
    }
  return (lex);
}
