/*
** circu.c for  in /home/lyto/my_select
** 
** Made by lyto
** Login   <lyto@epitech.net>
** 
** Started on  Fri Jan 18 14:06:44 2013 lyto
** Last update Sun May 26 13:26:32 2013 telenc_r
*/

#include	<stdlib.h>
#include	"lib.h"
#include	"parser.h"

void		my_show_list(t_line *first, t_link *link)
{
  t_line	*tmp;

  tmp = first;
  if (first != NULL)
    {
      while (tmp->next != first)
	{
	  my_putchar(tmp->arg);
	  tmp = tmp->next;
	}
      if (tmp != NULL)
	my_putchar(tmp->arg);
      if ((tmp = get_selected(link->line)) != NULL)
	{
	  while (tmp->next != first)
	    {
	      move_cur_left();
	      tmp = tmp->next;
	    }
	  move_cur_left();
	}
    }
}

static t_line	*put_after_selec(t_line *tmp,
				 t_line *new_maillon, t_line *one)
{
  tmp = tmp->prev;
  new_maillon->prev = tmp;
  new_maillon->next = tmp->next;
  new_maillon->prev->next = new_maillon;
  new_maillon->next->prev = new_maillon;
  if (new_maillon->next == one)
    return (new_maillon);
  return (one);
}

t_line		*put_in_list(t_line *one, char str)
{
  t_line	*tmp;
  t_line	*new_maillon;

  if (!(new_maillon = my_malloc(sizeof(t_line))))
    return (one);
  new_maillon->next = new_maillon;
  new_maillon->prev = new_maillon;
  new_maillon->arg = str;
  new_maillon->where = 0;
  new_maillon->select = 0;
  if (one == NULL)
    return (new_maillon);
  if ((tmp = get_selected(one)))
    return (put_after_selec(tmp, new_maillon, one));
  tmp = one;
  while (tmp->next != one)
    tmp = tmp->next;
  tmp->next = new_maillon;
  new_maillon->prev = tmp;
  new_maillon->next = one;
  one->prev = new_maillon;
  return (one);
}
