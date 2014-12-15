/*
** alias.h for alias in /home/ballen_d
** 
** Made by lyto
** Login   <ballen_d@lyto>
** 
** Started on  Thu May  2 10:05:18 2013 lyto
** Last update Thu May 23 16:21:00 2013 martre_s
*/

#ifndef			ALIAS_H_
#define			ALIAS_H_

#define WRONG_ALIAS	"Your line is wrong, usage : alias [alias] [command]\n"
#define IMPOSSIBLE_CMD	"Your command is not recognized in our shell.\n"
#define LOCAL		("PS1=" || "PS2=")

typedef	struct	s_alias	t_alias;
typedef	struct	s_local	t_local;

struct		s_alias
{
  char		*alias;
  char		*cmd;
  char		*prompt;
  t_alias	*nxt;
};

struct		s_local
{
  char		*variable;
  char		*value;
  t_local	*nxt;
};

int		alias_exist(t_alias *, char *);
t_alias		*change_the_alias(t_alias *, char *, char *);
void		display_alias(t_alias *);

#endif /* !ALIAS_H_ */
