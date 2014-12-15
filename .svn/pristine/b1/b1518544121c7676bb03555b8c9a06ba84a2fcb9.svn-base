/*
** check_grammar.c for check_grammar in /home/telenc_r/rendu/42sh/my
** 
** Made by telenc_r
** Login   <telenc_r@telenc>
** 
** Started on  Wed May 15 15:08:38 2013 telenc_r
** Last update Sun May 26 13:55:02 2013 telenc_r
*/

#include	<unistd.h>
#include	"parser.h"
#include	"types.h"
#include	"lib.h"

extern t_lex	*get_first_priority(t_lex *list)
{
  t_lex		*cur;

  cur = list;
  while (cur != NULL)
    {
      if (cur->type == S_OR || cur->type == S_AND)
	return (cur);
      cur = cur->nxt;
    }
  return (NULL);
}

extern t_lex	*get_second_priority(t_lex *list)
{
  t_lex		*cur;

  cur = list;
  while (cur != NULL)
    {
      if (cur->type == S_PIPE)
	return (cur);
      cur = cur->nxt;
    }
  return (NULL);
}

char		**remove_cmd(char **cmd)
{
  int		i;

  i = 0;
  while (cmd[i])
    {
      cmd[i] = cmd[i + 1];
      i++;
    }
  return (cmd);
}

extern int	do_change(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '$' || str[i] == '!')
	return (TRUE);
      i++;
    }
  return (FALSE);
}

extern char	*convert_char_to_str(char c)
{
  char		*res;

  if (!(res = my_malloc(sizeof(char) * 2)))
    return (NULL);
  res[0] = c;
  res[1] = '\0';
  return (res);
}
