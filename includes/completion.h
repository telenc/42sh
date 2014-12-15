/*
** completion.h for completion in /home/telenc_r/rendu/42sh/my/auto_completion
** 
** Made by telenc_r
** Login   <telenc_r@telenc>
** 
** Started on  Thu May 16 09:48:41 2013 telenc_r
** Last update Sun May 26 11:48:06 2013 telenc_r
*/

#ifndef COMPLETION_H_
# define COMPLETION_H_

typedef struct	s_complet	t_complet;

struct		s_complet
{
  char		*name;
  t_complet	*nxt;
};

t_complet	*add_completion(char *, t_complet *);
t_complet	*add_path_completion(t_complet *, t_link *, char *);

#endif /* !COMPLETION_H_ */
