/*
** cmd_or.c for cmd_or in /home/telenc_r/rendu/42sh/my/exec
** 
** Made by telenc_r
** Login   <telenc_r@telenc>
** 
** Started on  Thu May 16 15:00:17 2013 telenc_r
** Last update Sat May 18 18:49:43 2013 telenc_r
*/

#include	<unistd.h>
#include	"parser.h"
#include	"types.h"

extern int	exec_cmd_or(t_node *node, t_link *link)
{
  if (node->left != NULL && exec_cmd_type(node->left, link) == FALSE)
    if (node->right != NULL)
      return (exec_cmd_type(node->right, link));
  return (TRUE);
}
