/*
** env.c for env in /home/bodart/projets/Tek1/42sh
** 
** Made by BODART Louis
** Login   <bodart@bodart-l-pc>
** 
** Started on  Sat May 18 15:45:30 2013 BODART Louis
** Last update Thu May 23 16:49:24 2013 martre_s
*/

#include	<stdlib.h>
#include	"parser.h"

int		builtin_env(t_link *link, char **cmd)
{
  t_env		*tmp;

  (void)cmd;
  tmp = link->env;
  while (tmp != NULL)
    {
      my_printf("%s=%s\n", tmp->name, tmp->value);
      tmp = tmp->nxt;
    }
  return (0);
}
