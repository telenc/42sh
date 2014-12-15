/*
** get_next_line.c for get_next_line in /home/bodart/projets/Tek1/getnextline/v2
** 
** Made by louis bodart
** Login   <bodart_l@epitech.net>
** 
** Started on Fri Dec 14 16:47:48 2012 louis bodart
** Last update Sat May 25 21:16:29 2013 BODART Louis
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"get_next_line.h"
#include	"lib.h"

static t_list	*char_in_list(t_list *list, char c)
{
  t_list	*new_element;
  t_list	*tmp;

  if ((new_element = my_malloc(sizeof(t_list))) == NULL)
    return (list);
  new_element->caracter = c;
  new_element->nxt = NULL;
  if (list == NULL)
    return (new_element);
  else
    {
      tmp = list;
      while (tmp->nxt != NULL)
	tmp = tmp->nxt;
      tmp->nxt = new_element;
      return (list);
    }
}

static int	tab_size(t_list *tmp)
{
  int		i;

  i = 0;
  while (tmp->nxt != NULL && tmp->caracter != '\n')
    {
      tmp = tmp->nxt;
      i++;
    }
  return (i);
}

static int	check_list(t_list *list, int len)
{
  t_list	*tmp;

  tmp = list;
  while (tmp->nxt != NULL && tmp->caracter != '\n')
    tmp = tmp->nxt;
  if (tmp->caracter == '\n' || (tmp->nxt == NULL && len == 0))
    return (1);
  return (0);
}

static char	*list_in_tab(t_list **list)
{
  t_list	*fptr;
  t_list	*tmp;
  char		*tab;
  int		i;

  tmp = (*list);
  if ((tab = my_malloc(sizeof(char) * (tab_size(tmp) + 2))) == NULL)
    return (NULL);
  tab = my_memset(tab, 0, (tab_size(tmp) + 2));
  i = 0;
  while ((*list) != NULL && (*list)->caracter != '\n')
    {
      fptr = (*list);
      tab[i++] = (*list)->caracter;
      (*list) = (*list)->nxt;
      free(fptr);
    }
  if ((*list) != NULL)
    {
      fptr = (*list);
      (*list) = (*list)->nxt;
      free(fptr);
    }
  return (tab);
}

extern char	*get_next_line(const int fd)
{
  static t_list	*s;
  char		*tab;
  char		buffer[MAX_READ + 1];
  int		len;
  int		i;

  i = 0;
  while (i < (MAX_READ + 1))
    buffer[i++] = 0;
  i = 0;
  if ((len = read(fd, buffer, MAX_READ)) == -1)
    return (NULL);
  while (len != 0 && buffer[i])
    s = char_in_list(s, buffer[i++]);
  if (s == NULL)
    return (NULL);
  if (check_list(s, len) == 1)
    {
      tab = list_in_tab(&s);
      return (tab);
    }
  else
    get_next_line(fd);
  return (NULL);
}
