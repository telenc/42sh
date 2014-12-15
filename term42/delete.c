/*
** selection.c for selection in /home/lyto/my_select
** 
** Made by lyto
** Login   <lyto@lyto>
** 
** Started on  Sat Jan 19 12:59:25 2013 lyto
** Last update Thu May 23 18:15:40 2013 martre_s
*/

#include	<termios.h>
#include	<stdlib.h>
#include	<curses.h>
#include	<term.h>
#include	"parser.h"

void		selection_up(t_line *t)
{
  t_line	*tmp;

  tmp = t;
  while (tmp->select != 1)
    tmp = tmp->next;
  tmp->select = 2;
  tmp->next->select = 1;
}

t_line		*delete_last_line(t_line *line)
{
  t_line	*tmp;

  if (line == NULL)
    return (NULL);
  else if (line->prev == line)
    {
      free(line);
      return (NULL);
    }
  tmp = line->prev;
  tmp->next->prev = tmp->prev;
  tmp->prev->next = tmp->next;
  free(tmp);
  return (line);
}

t_line		*delete_char_line(t_line *line)
{
  t_line	*tmp;

  tmp = get_selected(line);
  if (tmp != NULL && tmp != line)
    {
      tmp = tmp->prev;
      tmp->prev->next = tmp->next;
      tmp->next->prev = tmp->prev;
      if (tmp == line)
	line = tmp->next;
      free(tmp);
      tmp = get_selected(line);
      return (line);
    }
  else
    return (delete_last_line(line));
}
