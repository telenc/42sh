/*
** exclamation_histo.c for exclamation_histo in /home/martre_s/Teck1/42/history
** 
** Made by martre_s
** Login   <martre_s@steven>
** 
** Started on  Mon May 20 13:51:30 2013 martre_s
** Last update Sun May 26 16:49:08 2013 telenc_r
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"histo.h"
#include	"parser.h"
#include	"lib.h"

t_excl		*params_excla(t_excl *exclam, char *str)
{
  t_excl	*tmp;
  t_excl	*new;

  if (!(new = my_malloc(sizeof(t_excl))))
    return (NULL);
  new->str = str;
  new->next = NULL;
  if (exclam == NULL)
    return (new);
  tmp = exclam;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = new;
  return (exclam);
}

char		*compare_command_histo(char *str, t_histo *histo)
{
  t_histo	*tmp;

  tmp = histo;
  if (tmp == NULL)
    return (NULL);
  while (tmp->next != NULL)
    tmp = tmp->next;
  while (tmp->prev != NULL)
    {
      if (my_strncmp(tmp->command, str, my_strlen(str)) == 0)
	{
	  my_printf("%s\n", tmp->command);
	  return (tmp->command);
	}
      tmp = tmp->prev;
    }
  return (NULL);
}

char		*get_good_excla(char *str)
{
  char		*tmp;
  int		i;
  int		k;

  i = 0;
  k = 0;
  if (!(tmp = my_malloc(sizeof(char) * my_strlen(str) + 1)))
    return (NULL);
  while (str[i] != '\0' && str[i] != '!')
    tmp[k++] = str[i++];
  tmp[k] = '\0';
  return (tmp);
}

t_excl		*replace_excla(t_histo *histo, char *str)
{
  int		i;
  t_excl	*exclam;

  i = 0;
  exclam = NULL;
  while (str[i])
    {
      if (str[i] == '!' && str[i + 1] == '!')
	{
	  exclam = params_excla(exclam, get_last_histo(histo));
	  str = delete_excla(str, 1);
	  i = 0;
	}
      else if (str[i + 1] != '\0' && str[i] == '!')
	{
	  str = delete_excla(str, 0);
	  exclam = add_params_in_excl(exclam, str, histo);
	  str = delete_excla(str, my_strlen(get_good_excla(str) - 1));
	  i = 0;
	}
      else
	i++;
    }
  return (exclam);
}

char		*exec_exclamation(char *str, t_histo *histo)
{
  t_excl	*exclam;
  t_excl	*tmp;
  char		*good_str;
  int		i;

  exclam = replace_excla(histo, str);
  tmp = exclam;
  i = 0;
  if (exclam == NULL)
    return (NULL);
  while (tmp != NULL)
    {
      if (tmp->str != NULL && i == 0)
	{
	  good_str = my_strdup(tmp->str);
	  i++;
	}
      else if (tmp->str != NULL)
	good_str = my_strcat(good_str, my_strdup(tmp->str));
      tmp = tmp->next;
    }
  free_list(exclam);
  return (good_str);
}
