/*
** moved.c for moved in /home/telenc_r/rendu/42sh/my
** 
** Made by telenc_r
** Login   <telenc_r@telenc>
** 
** Started on  Wed May 22 13:45:56 2013 telenc_r
** Last update Sun May 26 13:29:41 2013 telenc_r
*/

#include	<unistd.h>
#include	"parser.h"

extern t_line	*get_selected(t_line *line)
{
  t_line	*tmp;

  tmp = line;
  if (tmp != NULL)
    {
      while (tmp->next != line)
	{
	  if (tmp->select == 1)
	    return (tmp);
	  tmp = tmp->next;
	}
      if (tmp->select == 1)
	return (tmp);
    }
  return (FALSE);
}

int		change_selected_left(t_link *link)
{
  t_line	*selec;

  if (link->line != NULL)
    {
      if ((selec = get_selected(link->line)))
	{
	  if (selec != link->line)
	    {
	      selec->prev->select = 1;
	      selec->select = 0;
	      return (TRUE);
	    }
	  return (FALSE);
	}
      else
	link->line->prev->select = 1;
      return (TRUE);
    }
  return (FALSE);
}

int		change_selected_right(t_link *link)
{
  t_line	*selec;

  if (link->line != NULL)
    {
      if ((selec = get_selected(link->line)))
	{
	  selec->select = 0;
	  if (selec != link->line->prev)
	    selec->next->select = 1;
	  return (TRUE);
	}
    }
  return (FALSE);
}
