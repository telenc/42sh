/*
** my_count_str.c for my_count_str in /home/bodart/projets/Tek1/LabC
** 
** Made by louis bodart
** Login   <bodart_l@epitech.net>
** 
** Started on Fri Mar  8 14:58:11 2013 louis bodart
** Last update Fri Mar  8 15:04:07 2013 BODART Louis
*/

int		my_count_str(char *str, char *sep)
{
  int		occurences;
  int		str_pos;
  int		sep_pos;

  occurences = 0;
  str_pos = 0;
  sep_pos = 0;
  while (str[str_pos])
    {
      if (str[str_pos] == sep[sep_pos])
	sep_pos++;
      else
	sep_pos = 0;
      if (sep_pos == my_strlen(sep))
	{
	  sep_pos = 0;
	  occurences++;
	}
      str_pos++;
    }
  return (occurences);
}
