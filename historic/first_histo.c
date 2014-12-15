/*
** first_histo.c for first_histo in /home/martre_s/Teck1/42
** 
** Made by martre_s
** Login   <martre_s@steven>
** 
** Started on  Sun May 19 15:54:23 2013 martre_s
** Last update Sun May 26 14:16:24 2013 martre_s
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"histo.h"
#include	"parser.h"

int		max_histo(t_histo *histo)
{
  t_histo	*tmp;
  int		i;

  tmp = histo;
  while (tmp != NULL)
    {
      i++;
      tmp = tmp->next;
    }
  if (i >= 1000)
    return (1);
  return (0);
}

t_histo		*get_hist(t_link *link, char *str, int command)
{
  link->histo = add_histo(link->histo, str, command);
  if (max_histo(link->histo) == 1)
    link->histo = delete_first(link->histo);
  write_histo(link);
  return (link->histo);
}
