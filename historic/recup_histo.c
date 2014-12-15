/*
** recup_histo.c for recup_histo in /home/martre_s/Teck1/42
** 
** Made by martre_s
** Login   <martre_s@steven>
** 
** Started on  Tue May 14 14:22:41 2013 martre_s
** Last update Sun May 26 14:46:59 2013 telenc_r
*/

#include	<sys/stat.h>
#include	<fcntl.h>
#include	<sys/types.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	"get_next_line.h"
#include	"histo.h"
#include	"parser.h"
#include	"lib.h"

char		*get_histo_command(char **cmd)
{
  int		tmp;
  char		*str;

  tmp = 1;
  str = my_strdup("");
  if (cmd[0] && cmd[1])
    {
      while (cmd[tmp])
	{
	  str = my_strcat(str, cmd[tmp]);
	  str = my_strcat(str, " ");
	  tmp++;
	}
    }
  return (str);
}

t_histo		*add_pre_histo(t_histo *histo, char **cmd)
{
  t_histo	*tmp;
  t_histo	*new;

  if (my_getnbr(cmd[0]) == 0)
    return (histo);
  if (!(new = my_malloc(sizeof(t_histo))))
    return (histo);
  new->nbr_command = my_getnbr(cmd[0]);
  new->command = my_strdup(cmd[1]);
  new->aff_command = 0;
  if (cmd[2] != NULL)
    new->command = get_histo_command(cmd);
  new->prev = NULL;
  new->next = NULL;
  if (histo == NULL)
    return (new);
  tmp = histo;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = new;
  new->prev = tmp;
  return (histo);
}

t_histo		*recup_history(t_histo *histo)
{
  int		fd;
  char		*str;
  char		**cmd;
  int		k;

  fd = open("42histo", O_RDONLY);
  k = 0;
  if (fd == -1)
    return (NULL);
  while ((str = get_next_line(fd)) && k <= 1000)
    {
      str = my_epur_str(str);
      cmd = my_explode(str, ' ');
      if (cmd[0] != NULL && cmd[1] != NULL)
	{
	  histo = add_pre_histo(histo, cmd);
	  k++;
	}
      free_tab(cmd);
      free(str);
    }
  close(fd);
  return (histo);
}

int		get_int_history(t_histo *histo)
{
  int		k;
  t_histo	*tmp;

  k = 0;
  tmp = histo;
  if (histo == NULL)
    return (k + 1);
  while (tmp != NULL)
    {
      if (k < tmp->nbr_command)
	k = tmp->nbr_command;
      tmp = tmp->next;
    }
  return (k + 1);
}
