/*
** main.c for main in /home/bodart/projets/SRC
** 
** Made by louis bodart
** Login   <bodart_l@epitech.net>
** 
** Started on Tue Jan  1 14:45:27 2013 louis bodart
** Last update Sun May 26 17:54:59 2013 BODART Louis
*/

#include	<stdlib.h>
#include	<signal.h>
#include	"alias.h"
#include	"parser.h"
#include	"lib.h"

static void	free_end(t_link *link)
{
  free_histo(link->histo);
  free_env(link->env);
  free_alias(link->alias);
  free_local(link->local);
}

static void	sig(int sign)
{
  if (sign == SIGINT)
    {
      kill(-2, SIGINT);
      my_putchar('\n');
    }
}

int		main(int argc, char **argv, char **envp)
{
  t_link	link;

  signal(SIGINT, sig);
  link.term_caps = 0;
  link.exit_status = 0;
  link.exit_code = 0;
  link.histo_path = my_strcat(get_pwd(), "/42histo");
  link.built = init_builtins();
  link.env = get_environment(envp);
  if (argc > 1 && mode_passif(&link, argv, envp) == TRUE)
    return (1);
  link.alias = NULL;
  link.histo = NULL;
  take_my_bashrc(&link, ".42shrc");
  link.histo = recup_history(NULL);
  if (term_init(&link, envp) == TRUE)
    {
      if (term_mode(&link) == 4)
	show_prompt(&link);
      else
	finish_term(&link);
    }
  else
    show_prompt(&link);
  free_end(&link);
  return (link.exit_code);
}
