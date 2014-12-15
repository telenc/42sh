/*
** free_histo.c for free_histo in /home/martre_s/Teck1/42
** 
** Made by martre_s
** Login   <martre_s@steven>
** 
** Started on  Tue May 21 11:23:54 2013 martre_s
** Last update Sun May 26 17:32:09 2013 BODART Louis
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"histo.h"
#include	"parser.h"

t_histo		*free_histo(t_histo *histo)
{
  t_histo	*tmp;

  if (histo == NULL)
    return (NULL);
  else
    {
      tmp = histo->next;
      free(histo->command);
      free(histo);
      return (free_histo(tmp));
    }
}

t_excl		*free_list(t_excl *exclam)
{
  t_excl	*tmp;

  if (exclam == NULL)
    return (NULL);
  else
    {
      tmp = exclam->next;
      free(exclam->str);
      free(exclam);
      return (free_list(tmp));
    }
}
