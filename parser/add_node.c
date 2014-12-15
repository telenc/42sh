/*
** add_node.c for add_node in /home/bodart/projets/Tek1/42sh
** 
** Made by BODART Louis
** Login   <bodart@bodart-l-pc>
** 
** Started on  Mon May 13 14:57:47 2013 BODART Louis
** Last update Sat May 25 23:00:32 2013 BODART Louis
*/

#include	<stdlib.h>
#include	"parser.h"
#include	"types.h"
#include	"lib.h"

extern t_node	*add_and_or_node(t_node *root, t_lex *tmp)
{
  t_node	*tmp_node;
  t_node	*new_node;

  if (!(new_node = my_malloc(sizeof(t_node))))
    return (root);
  new_node->type = tmp->type;
  new_node->word = my_strdup(tmp->word);
  new_node->left = NULL;
  new_node->right = NULL;
  if (root == NULL)
    return (new_node);
  if (root->right == NULL)
    {
      root->right = new_node;
      return (root);
    }
  tmp_node = root->right;
  while (tmp_node->left != NULL)
    tmp_node = tmp_node->left;
  tmp_node->left = new_node;
  return (root);
}
