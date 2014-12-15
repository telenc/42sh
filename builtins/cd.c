/*
** cd.c for cd in /home/bodart/projets/Tek1/42sh
** 
** Made by BODART Louis
** Login   <bodart@bodart-l-pc>
** 
** Started on  Mon May 20 10:37:08 2013 BODART Louis
** Last update Sun May 26 18:43:44 2013 BODART Louis
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"lib.h"
#include	"parser.h"

char		*upgrade_pwd(t_link *link, char *pwd, char *element, int i)
{
  char		*new_pwd;
  char		*tmp;

  if (i == 0 && !element[0])
    {
      free(pwd);
      pwd = my_strdup("/");
      return (pwd);
    }
  if (i == 0 && (!my_strcmp(element, "~") &&
		 (tmp = get_var_value(link, "HOME"))))
    {
      free(pwd);
      pwd = my_strdup(tmp);
      return (pwd);
    }
  if (!element[0] || !my_strcmp(element, "."))
    return (pwd);
  tmp = element;
  if (my_count_char(pwd, '/') > 1 || (my_count_char(pwd, '/') == 1 && pwd[1]))
    tmp = my_strcat("/", element);
  new_pwd = my_strcat(pwd, tmp);
  free(tmp);
  free(pwd);
  return (new_pwd);
}

char		*downgrade_pwd(char *pwd)
{
  int		i;
  int		total_slashes;
  int		current_slashes;

  i = 0;
  current_slashes = 0;
  total_slashes = my_count_char(pwd, '/');
  if (total_slashes == 1 && !pwd[1])
    return (pwd);
  if (total_slashes == 1 && pwd[1])
    {
      pwd[1] = '\0';
      return (pwd);
    }
  while (pwd[i] && current_slashes < total_slashes)
    {
      if (pwd[i] == '/')
	current_slashes++;
      if (current_slashes < total_slashes)
	i++;
    }
  pwd[i] = '\0';
  return (pwd);
}

void		update_pwd(t_link *link, char *new_pwd, char *input)
{
  char		*old_pwd;
  char		*cmd[4];

  old_pwd = get_pwd();
  if (!chdir(new_pwd))
    {
      cmd[0] = "";
      cmd[1] = "PWD";
      cmd[2] = new_pwd;
      cmd[3] = NULL;
      builtin_setenv(link, cmd);
      cmd[1] = "OLDPWD";
      cmd[2] = old_pwd;
      builtin_setenv(link, cmd);
    }
  else
    {
      my_printf("42sh: cd: %s: No such file or directory\n", input);
      free(new_pwd);
    }
  free(old_pwd);
}

int		particular_cases(t_link *link, int type)
{
  char		*tmp;

  if (type == 0)
    {
      if ((tmp = get_var_value(link, "HOME")) != NULL)
	if (tmp[0] != '\0')
	  update_pwd(link, tmp, tmp);
      return (42);
    }
  if (type == 1)
    {
      if ((tmp = get_var_value(link, "OLDPWD")) != NULL)
	update_pwd(link, tmp, tmp);
      return (42);
    }
  if (type == 2)
    {
      if ((tmp = my_strdup("/")) != NULL)
	update_pwd(link, tmp, tmp);
      return (42);
    }
  return (42);
}

int		builtin_cd(t_link *link, char **cmd)
{
  char		**tab_two;
  char		*pwd;
  int		i;

  i = 0;
  if (!cmd[1] || (cmd[1] && !cmd[1][0]))
    return (particular_cases(link, 0));
  if (!my_strcmp(cmd[1], "-"))
    return (particular_cases(link, 1));
  if (!my_strcmp(cmd[1], "/"))
    return (particular_cases(link, 2));
  tab_two = my_explode(cmd[1], '/');
  pwd = get_pwd();
  while (tab_two[i])
    {
      if (!my_strcmp("..", tab_two[i]))
	pwd = downgrade_pwd(pwd);
      else
	pwd = upgrade_pwd(link, pwd, tab_two[i], i);
      i++;
    }
  update_pwd(link, pwd, cmd[1]);
  return (TRUE);
}
