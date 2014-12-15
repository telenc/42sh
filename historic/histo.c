/*
** histo.c for histo in /home/martre_s/Teck1/42
** 
** Made by martre_s
** Login   <martre_s@steven>
** 
** Started on  Thu May  2 16:05:35 2013 martre_s
** Last update Sun May 26 13:31:44 2013 martre_s
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	"histo.h"
#include	"parser.h"
#include	"lib.h"

void		write_histo(t_link *link)
{
  int		fd;
  t_histo	*tmp;

  fd = open(link->histo_path, O_CREAT | O_WRONLY | O_TRUNC, 0664);
  tmp = link->histo;
  while (tmp != NULL)
    {
      write(fd, " ", 1);
      write(fd, my_put_nbr_str(tmp->nbr_command),
	    my_strlen(my_put_nbr_str(tmp->nbr_command)));
      write(fd, " ", 1);
      write(fd, tmp->command, my_strlen(tmp->command));
      write(fd, "\n", 1);
      tmp = tmp->next;
    }
  close(fd);
}

int		if_poss_history(t_histo *histo, char *str)
{
  t_histo	*tmp;

  tmp = histo;
  if (histo == NULL)
    return (1);
  if (str == NULL)
    return (0);
  while (tmp->next != NULL)
    tmp = tmp->next;
  if (my_strcmp(tmp->command, str) == 0)
    return (0);
  return (1);
}

int		aff_history(t_histo *histo)
{
  t_histo	*tmp;

  tmp = histo;
  while (tmp != NULL)
    {
      my_printf(" %d -- %s\n", tmp->nbr_command, tmp->command);
      tmp = tmp->next;
    }
  return (TRUE);
}

t_histo		*add_histo(t_histo *histo, char *str, int command)
{
  t_histo       *new;
  t_histo	*tmp;

  if (str == NULL)
    return (histo);
  if (!(new = my_malloc(sizeof(t_histo))))
    return (histo);
  new->command = my_strdup(str);
  new->nbr_command = command;
  new->next = NULL;
  new->prev = NULL;
  new->aff_command = 0;
  if (histo == NULL)
    return (new);
  tmp = histo;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = new;
  new->prev = tmp;
  return (histo);
}

t_histo		*delete_first(t_histo *histo)
{
  t_histo      	*save;

  if (histo == NULL)
    return (NULL);
  save = histo->next;
  free(histo->command);
  free(histo);
  save->prev = NULL;
  return (save);
}
