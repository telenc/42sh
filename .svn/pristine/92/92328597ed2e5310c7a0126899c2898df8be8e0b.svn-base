/*
** histo.h for histo in /home/martre_s/Teck1/42/42sh-2017-bodart_l/includes
** 
** Made by martre_s
** Login   <martre_s@steven>
** 
** Started on  Mon May 20 12:47:18 2013 martre_s
** Last update Thu May 23 16:32:41 2013 martre_s
*/

#ifndef HISTO_H_
# define HISTO_H_

#define	NAME_HISTO	".42histo"
#define	MAX_HISTO	1000

typedef struct	s_histo	t_histo;
typedef struct	s_excl	t_excl;

struct		s_histo
{
  char		*command;
  int		aff_command;
  int		nbr_command;
  t_histo	*next;
  t_histo	*prev;
};

struct		s_excl
{
  char		*str;
  t_excl	*next;
};

void		free_tab(char **);

#endif /* !HISTO_H_ */
