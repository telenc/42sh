/*
** lib.h for lib in /home/bodart/projets/SRC/lib
** 
** Made by louis bodart
** Login   <bodart_l@epitech.net>
** 
** Started on Mon Dec 31 15:57:13 2012 louis bodart
** Last update Sun May 26 18:38:36 2013 telenc_r
*/

#ifndef LIB_H_
# define LIB_H_

#include	<stdlib.h>

int	my_count_char(char *, int);
char	*my_epur_str(char *);
char	**my_explode(char *, int);
char	**my_remove_in_tab(char **, int);
int	my_getnbr(char *);
void	*my_malloc(size_t);
void	*my_memset(char *, int, int);
int	my_printf(const char *, ...);
void	my_put_nbr(int);
void	my_putchar(unsigned char);
void	my_putstr(char *);
char	*my_revstr(char *);
char	*my_strcat(char *, char *);
int	my_strcmp(char *, char *);
int	my_strncmp(char *, char *, int);
char	*my_strcut(char *, int);
char	*my_strdup(char *);
int	my_strlen(char *);
void	my_put_nbr_aff_sign(int);
void	my_putnbr_base_zero(unsigned int, char *);
int	pf_my_putstr_base(char *);
void	my_put_nbr_ui(unsigned int);
void	p_flag(unsigned int);
void	my_putstr(char *);
void	my_putnbr_base(unsigned int, char *);

#endif /* !LIB_H_ */
