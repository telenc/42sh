/*
** build_trees.c for build_trees in /home/bodart/projets/Tek1/42sh
** 
** Made by BODART Louis
** Login   <bodart@bodart-l-pc>
** 
** Started on  Mon May 13 14:46:53 2013 BODART Louis
** Last update Sun May 26 19:07:22 2013 telenc_r
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"parser.h"
#include	"types.h"
#include	"lib.h"

static void	create_son(t_lex *cur_lex, t_lex *new_lex, t_node *son)
{
  if (cur_lex != new_lex)
    {
      son->left = build_node(cur_lex, son->left);
      son->left->parent = son;
    }
  if (new_lex->nxt != NULL)
    {
      new_lex->nxt->prv = NULL;
      son->right = build_node(new_lex->nxt, son->right);
      son->right->parent = son;
    }
}

extern t_node	*build_node(t_lex *cur, t_node *son)
{
  t_lex		*new_lex;
  t_lex		*cur_lex;

  if (cur == NULL)
    return (NULL);
  if ((new_lex = get_first_priority(cur))
      || (new_lex = get_second_priority(cur)))
    {
      son = create_node_by_lex(new_lex);
      if (new_lex->prv != NULL)
	new_lex->prv->nxt = NULL;
      cur_lex = new_lex;
      while (cur_lex->prv != NULL)
	cur_lex = cur_lex->prv;
      create_son(cur_lex, new_lex, son);
      free(new_lex);
    }
  else
    {
      son = create_node_by_lex(cur);
      free(cur);
    }
  return (son);
}

static t_lex	*has_other(t_lex *lex)
{
  t_lex		*sauv;

  while (lex != NULL && lex->type != S_SEMICOLON)
    lex = lex->nxt;
  if (lex != NULL)
    {
      if (lex->prv != NULL)
	lex->prv->nxt = NULL;
      sauv = lex;
      lex = lex->nxt;
      if (lex != NULL)
	lex->prv = NULL;
      free(sauv);
    }
  return (lex);
}

static t_trees		*add_tree(t_trees **list)
{
  t_trees		*new;
  t_trees		*tmp;

  if (!(new = my_malloc(sizeof(t_trees))))
    return (NULL);
  new->root = NULL;
  new->nxt = NULL;
  if (*list == NULL)
    {
      *list = new;
      return (new);
    }
  tmp = *list;
  while (tmp->nxt != NULL)
    tmp = tmp->nxt;
  tmp->nxt = new;
  return (new);
}

extern t_trees	*build_trees(t_lex *lex)
{
  t_trees	*tree;
  t_trees	*tmp;
  t_lex		*next;
  t_lex		*first;

  tree = NULL;
  while (lex != NULL && lex->type == S_SEMICOLON)
    lex = lex->nxt;
  first = lex;
  next = lex;
  while ((next = has_other(next)))
    {
      tmp = add_tree(&tree);
      tmp->root = build_node(first, tmp->root);
      first = next;
    }
  tmp = add_tree(&tree);
  if (tmp)
    tmp->root = build_node(first, tmp->root);
  return (tree);
}
