/*
** init_builtins.c for init_builtins in /home/bodart/projets/Tek1/42sh
** 
** Made by BODART Louis
** Login   <bodart@bodart-l-pc>
** 
** Started on  Mon May 20 14:00:49 2013 BODART Louis
** Last update Sun May 26 17:06:21 2013 telenc_r
*/

#include	<stdlib.h>
#include	"parser.h"
#include	"builtins.h"
#include	"lib.h"

t_built		*add_builtin_in_list(t_built *built, char *name,
				     int (*function)(t_link *, char **))
{
  t_built	*new_element;
  t_built	*tmp;

  if (!(new_element = my_malloc(sizeof(t_built))))
    return (built);
  new_element->name = name;
  new_element->function = function;
  new_element->nxt = NULL;
  if (built == NULL)
    return (new_element);
  tmp = built;
  while (tmp->nxt != NULL)
    tmp = tmp->nxt;
  tmp->nxt = new_element;
  return (built);
}

t_built		*init_builtins(void)
{
  t_built	*built;

  built = NULL;
  built = add_builtin_in_list(built, "env", builtin_env);
  built = add_builtin_in_list(built, "setenv", builtin_setenv);
  built = add_builtin_in_list(built, "unsetenv", builtin_unsetenv);
  built = add_builtin_in_list(built, "cd", builtin_cd);
  built = add_builtin_in_list(built, "alias", builtin_alias);
  built = add_builtin_in_list(built, "history", builtin_histo);
  built = add_builtin_in_list(built, "exit", builtin_exit);
  built = add_builtin_in_list(built, "echo", builtin_echo);
  built = add_builtin_in_list(built, "source", builtin_source);
  built = add_builtin_in_list(built, "unalias", builtin_unalias);
  built = add_builtin_in_list(built, "man42", builtin_man);
  return (built);
}
