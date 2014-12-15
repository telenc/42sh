/*
** my_exit.c for my_exit in /home/bodart/projets/Tek1/42sh
** 
** Made by BODART Louis
** Login   <bodart@bodart-l-pc>
** 
** Started on  Sun May 26 00:17:58 2013 BODART Louis
** Last update Sun May 26 17:18:33 2013 BODART Louis
*/

#include	"lib.h"
#include	"parser.h"

int		builtin_exit(t_link *link, char **cmd)
{
  if (cmd[0] && cmd[1])
    link->exit_code= my_atoi(cmd[1]);
  else
    link->exit_code = 0;
  link->exit_status = 1;
  return (TRUE);
}
