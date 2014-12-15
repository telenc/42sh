/*
** my_remove_in_tab.c for my_remove_in_tab in /home/telenc_r/rendu/42sh/my
** 
** Made by telenc_r
** Login   <telenc_r@telenc>
** 
** Started on  Sat May 18 13:09:08 2013 telenc_r
** Last update Sun May 26 01:10:39 2013 telenc_r
*/

#include	<unistd.h>

extern char	**my_remove_in_tab(char **tab, int i)
{
  if (tab == NULL)
    return (NULL);
  while (tab[i] != NULL)
    {
      tab[i] = tab[i + 1];
      i++;
    }
  return (tab);
}
