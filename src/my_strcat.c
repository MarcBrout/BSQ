/*
** my_strcat.c for my_strcat in /home/brout_m/dev/lib
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Tue Oct  6 13:37:20 2015 marc brout
** Last update Mon Nov 30 18:15:06 2015 marc brout
*/

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;

  i = 0;
  while (dest[i])
    i++;
  j = 0;
  while (src[j])
    {
      dest[i] = src[j];
      j = j + 1;
      i = i + 1;
    }
  dest[i] = 0;
  return (dest);
}
