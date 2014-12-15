/*
** pre_lexer.c for pre_lexer in /home/bodart/projets/Tek1/42sh
** 
** Made by BODART Louis
** Login   <bodart@bodart-l-pc>
** 
** Started on  Sun May 19 14:26:26 2013 BODART Louis
** Last update Sun May 26 18:50:27 2013 telenc_r
*/

#include	<stdlib.h>
#include	"parser.h"
#include	"types.h"
#include	"lib.h"

char		**explode_command(t_link *link, char *str)
{
  char		**cmd;
  char		*alias;

  str = my_epur_str(str);
  cmd = my_explode_cote(str, ' ');
  if (cmd[0] && contain(cmd[0], '=') == TRUE)
    {
      local_var(link, cmd);
      while (cmd[0] && contain(cmd[0], '=') == TRUE)
	cmd = remove_cmd(cmd);
    }
  if (cmd[0] && (alias = check_in_alias(link->alias, cmd[0])))
    {
      cmd[0] = alias;
      alias = NULL;
    }
  return (replace_cmd(cmd, link));
}

void		replace_lexeme(t_link *link, t_lex *lex, int *is_modified)
{
  t_lex		*tmp;

  tmp = lex;
  while (tmp != NULL)
    {
      if (tmp->type == COMMAND)
	{
	  tmp->word = replace_all(link, tmp->word, is_modified);
	}
      tmp = tmp->nxt;
    }
}

void		replace_alias(t_link *link, t_lex *lex)
{
  t_lex		*tmp;
  char		**cmd;

  tmp = lex;
  while (tmp != NULL)
    {
      if (tmp->type == COMMAND)
	{
	  cmd = explode_command(link, tmp->word);
	  free(tmp->word);
	  tmp->word = concat_tab(cmd);
	}
      tmp = tmp->nxt;
    }
}

t_lex		*create_pre_lexer(char *line)
{
  t_lex		*lex;
  char		*str;
  int		i;

  i = 0;
  lex = NULL;
  if (!line)
    return (NULL);
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
      else
	i++;
    }
  return (lex);
}

char		*pre_lexer(t_link *link, char *line, int myrc)
{
  t_lex		*lex;
  int		is_modified;

  is_modified = 1;
  while (is_modified)
    {
      is_modified = 0;
      lex = create_pre_lexer(line);
      replace_lexeme(link, lex, &is_modified);
      line = concat_lexeme(lex);
    }
  if (myrc && if_poss_history(link->histo, line) == TRUE)
    link->histo = get_hist(link, line, get_int_history(link->histo));
  replace_alias(link, lex);
  line = concat_lexeme(lex);
  return (line);
}
