/*
** main.c for main in /home/lyto/my_select
** 
** Made by lyto
** Login   <lyto@lyto>
** 
** Started on  Tue Jan 15 12:10:53 2013 lyto
** Last update Sun May 26 16:15:33 2013 telenc_r
*/

#include		<termios.h>
#include		<stdlib.h>
#include		<curses.h>
#include		<term.h>
#include		"parser.h"
#include		"lib.h"

int		finish_term(t_link *link)
{
  link->term.termios = link->term.sauv;
  link->term_caps = 0;
  tcsetattr(0, TCSANOW, &(link->term.termios));
  link->term_caps = 0;
  return (FALSE);
}

int		term_init(t_link *link, char **envp)
{
  char		*env;

  env = envir(envp);
  if (env == NULL)
    return (FALSE);
  if (tcgetattr(0, &(link->term.termios)) != 0)
    return (FALSE);
  link->term.sauv = link->term.termios;
  link->term.termios.c_lflag &= ~(ICANON | ECHO | ISIG);
  link->term.termios.c_cc[VMIN] = 0;
  link->term.termios.c_cc[VTIME] = 1;
  if (tcsetattr(0, TCSANOW, &(link->term.termios)) != 0)
    return (FALSE);
  tgetent(NULL, env);
  link->term_caps = 1;
  return (TRUE);
}
