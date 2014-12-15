/*
** replace_all.c for replace_all in /home/telenc_r/rendu/42sh/my
** 
** Made by telenc_r
** Login   <telenc_r@telenc>
** 
** Started on  Mon May 20 10:24:13 2013 telenc_r
** Last update Sun May 26 18:31:17 2013 telenc_r
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"parser.h"
#include	"lib.h"

static int	check_char(char c, int type, int *first)
{
  if (c == '\0')
    return (FALSE);
  if ((type == 0 && *first == 0 && c == '$')
      || (type == 1 && *first == 0 && c == '!'))
    {
      *first = 1;
      if (type == 1 && c == '!')
	*first = 0;
      return (TRUE);
    }
  else
    *first = 1;
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    return (TRUE);
  else if ((c >= '0' && c <= '9') || c == '-')
    return (TRUE);
  else
    return (FALSE);
  return (FALSE);
}

static char	*change_var_env(char *str, int *i, t_link *link, char *result)
{
  char		*tmp;
  char		*sauv;
  char		*sauv2;
  int		first;

  first = 0;
  tmp = my_strdup("");
  while (check_char(str[*i], 0, &first) == TRUE)
    {
      sauv = tmp;
      sauv2 = convert_char_to_str(str[*i]);
      tmp = my_strcat(tmp, sauv2);
      free(sauv);
      free(sauv2);
      *i += 1;
    }
  sauv = result;
  tmp = check_in_env_var(link, tmp);
  tmp = my_strcat("\"", my_strcat(tmp, "\""));
  result = my_strcat(result, tmp);
  free(sauv);
  return (result);
}

static char	*change_var_histo(char *str, int *i, t_link *link, char *result)
{
  char		*tmp;
  char		*sauv;
  char		*sauv2;
  int		first;

  first = 0;
  tmp = my_strdup("");
  while (check_char(str[*i], 1, &first) == TRUE)
    {
      sauv = tmp;
      sauv2 = convert_char_to_str(str[*i]);
      tmp = my_strcat(tmp, sauv2);
      free(sauv);
      free(sauv2);
      *i += 1;
    }
  sauv = result;
  tmp = exec_exclamation(tmp, link->histo);
  if (tmp != NULL)
    {
      result = my_strcat(result, tmp);
      free(sauv);
    }
  return (result);
}

static int	replace_by_char(char *str, int *i, t_link *link, char **result)
{
  char		*sauv;
  char		*sauv2;

  if (str[*i] == '$')
    {
      *result = change_var_env(str, i, link, *result);
      return (1);
    }
  else if (str[*i] == '!')
    {
      *result = change_var_histo(str, i, link, *result);
      return (1);
    }
  else
    {
      sauv = *result;
      sauv2 = convert_char_to_str(str[*i]);
      *result = my_strcat(*result, sauv2);
      free(sauv);
      free(sauv2);
      (*i)++;
    }
  return (0);
}

extern char	*replace_all(t_link *link, char *str, int *is_modified)
{
  int		i;
  char		*result;

  if (do_change(str) == FALSE)
    return (str);
  result = my_strdup("");
  i = 0;
  while (str[i] != '\0')
    {
      if (replace_by_char(str, &i, link, &result) == 1)
	*is_modified = 1;
    }
  return (result);
}
