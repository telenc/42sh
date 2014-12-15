/*
** my_put_nbr_str.c<2> for my_put_nbr_str in /home/martre_s/Teck1/108monster
** 
** Made by martre_s
** Login   <martre_s@steven>
** 
** Started on  Sun Mar 31 19:01:47 2013 martre_s
** Last update Sun May 26 14:25:30 2013 martre_s
*/

#include	<unistd.h>
#include	"histo.h"
#include	"lib.h"

static int	abso(int nb)
{
  if (nb < 0)
    return (nb * -1);
  return (nb);
}

static int	nbr_of_malloc(int i, int tmp)
{
  while (tmp > 9)
    {
      tmp /= 10;
      i++;
    }
  return (i);
}

char		*my_put_nbr_str(int nb)
{
  char		*str;
  int		tmp;
  int		i;

  tmp = abso(nb);
  i = 0;
  if (!(str = my_malloc(sizeof(char) * (nbr_of_malloc(i, tmp) + 2))))
    return (NULL);
  tmp = 0;
  if (nb < 0)
    tmp++;
  nb = abso(nb);
  while (nb > 0)
    {
      str[i++] = (nb % 10) + 48;
      nb = nb / 10;
    }
  str[i] = '\0';
  str = my_revstr(str);
  if (tmp == 1)
    str = my_strcat("-", str);
  return (str);
}
