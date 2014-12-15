/*
** separators.c for separators in /home/bodart/projets/Tek1/42sh/parser
** 
** Made by BODART Louis
** Login   <bodart@bodart-l-pc>
** 
** Started on  Mon May  6 15:29:19 2013 BODART Louis
** Last update Thu May 23 18:04:02 2013 martre_s
*/

#include	"lib.h"
#include	"parser.h"
#include	"types.h"

extern int	is_separator(char c)
{
  int		i;

  i = 0;
  while (SEP_CHARS[i])
    if (SEP_CHARS[i++] == c)
      return (1);
  return (0);
}

extern int	get_separator_type(char *str)
{
  if (!my_strcmp(str, "|"))
    return (S_PIPE);
  if (!my_strcmp(str, ";"))
    return (S_SEMICOLON);
  if (!my_strcmp(str, "&&"))
    return (S_AND);
  if (!my_strcmp(str, "||"))
    return (S_OR);
  return (UNKNOWN);
}
