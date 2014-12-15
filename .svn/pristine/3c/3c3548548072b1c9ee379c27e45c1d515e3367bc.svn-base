/*
** exec_histo.c for exec_histo in /home/martre_s/Teck1/42
** 
** Made by martre_s
** Login   <martre_s@steven>
** 
** Started on  Fri May 17 14:52:42 2013 martre_s
** Last update Sun May 26 17:22:09 2013 telenc_r
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"histo.h"
#include	"parser.h"
#include	"lib.h"

char		*delete_excla(char *str, int nbr_supp)
{
  char		*tmp;
  int		i;
  int		k;

  if (!(tmp = my_malloc(sizeof(char) * my_strlen(str) + 1)))
    return (NULL);
  i = 0;
  k = 0;
  if (str == NULL)
    return (NULL);
  while (str[i])
    {
      if (i > nbr_supp)
	tmp[k++] = str[i];
      i++;
    }
  tmp[k] = '\0';
  return (tmp);
}

char		*back_up_histo(t_histo *histo, int nbr)
{
  t_histo	*tmp;
  int		a;

  if (histo == NULL)
    return (my_strdup(""));
  tmp = histo;
  while (tmp->next != NULL)
    tmp = tmp->next;
  a = -1;
  while (a > nbr)
    {
      if (tmp->prev == NULL)
	{
	  my_printf("!%d event not found\n", nbr);
	  return (my_strdup(""));
	}
      tmp = tmp->prev;
      a--;
    }
  return (tmp->command);
}

char		*get_int_command(t_histo *histo, int nbr)
{
  t_histo	*tmp;

  tmp = histo;
  if (histo == NULL)
    return (my_strdup(""));
  while (tmp != NULL)
    {
      if (nbr == tmp->nbr_command)
	return (tmp->command);
      tmp = tmp->next;
    }
  my_printf("!%d event not found\n", nbr);
  return (my_strdup(""));
}

char		*get_last_histo(t_histo *histo)
{
  t_histo	*tmp;

  tmp = histo;
  if (histo == NULL)
    return (my_strdup(""));
  while (tmp->next != NULL)
    tmp = tmp->next;
  return (my_strdup(tmp->command));
}

t_excl		*add_params_in_excl(t_excl *exclam, char *str, t_histo *histo)
{
  int		nbr;
  char		*cmd;

  if ((nbr = my_atoi(get_good_excla(str))) < 0)
    exclam = params_excla(exclam, back_up_histo(histo, nbr));
  else if ((nbr = my_atoi(get_good_excla(str))) > 0)
    exclam = params_excla(exclam, get_int_command(histo, nbr));
  else
    if ((cmd = compare_command_histo(str, histo)) == NULL)
      exclam = params_excla(exclam, get_good_excla(str));
    else
      exclam = params_excla(exclam, cmd);
  return (exclam);
}
