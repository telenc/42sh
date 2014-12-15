/*
** builting_histo.c for builting_histo in /home/martre_s/Teck1/42
** 
** Made by martre_s
** Login   <martre_s@steven>
** 
** Started on  Tue May 21 11:28:47 2013 martre_s
** Last update Sun May 26 14:38:08 2013 telenc_r
*/

#include	<unistd.h>
#include	"parser.h"
#include	"histo.h"
#include	"lib.h"

int		builtin_histo(t_link *link, char **cmd)
{
  t_histo	*histo;

  histo = link->histo;
  if (histo == NULL)
    return (FALSE);
  if (cmd[1] == NULL)
    aff_history(histo);
  else if (my_strcmp(cmd[1], "-c") == 0)
    {
      histo = free_histo(histo);
      write_histo(link);
      link->histo = histo;
    }
  else
    return (FALSE);
  return (TRUE);
}

char		*up_histo(t_link *link)
{
  t_histo	*sauv;
  t_histo	*tmp;

  tmp = link->histo;
  sauv = tmp;
  while (tmp != NULL)
    {
      if (tmp->aff_command == 1)
	{
	  if (tmp->prev != NULL && tmp->prev->command != NULL)
	    {
	      tmp->aff_command = 0;
	      tmp->prev->aff_command = 1;
	      return (tmp->prev->command);
	    }
	  else if (tmp != link->histo)
	    return (my_strdup(""));
	  else if (tmp == link->histo)
	    return (tmp->command);
	}
      sauv = tmp;
      tmp = tmp->next;
    }
  sauv->aff_command = 1;
  return (sauv->command);
}

int		has_histo_aff(t_link *link)
{
  t_histo	*tmp;

  tmp = link->histo;
  while (tmp != NULL)
    {
      if (tmp->aff_command == 1)
	return (TRUE);
      tmp = tmp->next;
    }
  return (FALSE);
}

char		*down_histo(t_link *link)
{
  t_histo	*histo;
  t_histo	*tmp;

  histo = link->histo;
  tmp = histo;
  while (tmp != NULL)
    {
      if (tmp->aff_command == 1)
	{
	  if (tmp->next != NULL)
	    {
	      tmp->aff_command = 0;
	      tmp->next->aff_command = 1;
	      return (tmp->next->command);
	    }
	  else
	    {
	      tmp->aff_command = 0;
	      return (my_strdup(""));
	    }
	}
      tmp = tmp->next;
    }
  return (my_strdup(""));
}

t_histo		*reset_histo(t_link *link)
{
  t_histo	*histo;
  t_histo	*tmp;

  histo = link->histo;
  tmp = histo;
  while (tmp != NULL)
    {
      tmp->aff_command = 0;
      tmp = tmp->next;
    }
  return (histo);
}
