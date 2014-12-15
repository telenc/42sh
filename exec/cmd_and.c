/*
** cmd_and.c for cmd_and in /home/telenc_r/rendu/42sh/my/exec
** 
** Made by telenc_r
** Login   <telenc_r@telenc>
** 
** Started on  Thu May 16 14:57:13 2013 telenc_r
** Last update Sat May 18 18:48:57 2013 telenc_r
*/

#include	<unistd.h>
#include	"parser.h"
#include	"types.h"

extern int	exec_cmd_and(t_node *node, t_link *link)
{
  if (node->left != NULL && exec_cmd_type(node->left, link) == TRUE)
    if (node->right != NULL)
      return (exec_cmd_type(node->right, link));
  return (FALSE);
}
