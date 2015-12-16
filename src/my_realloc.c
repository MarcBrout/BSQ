/*
** my_realloc.c for lib
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Mon Nov 30 10:41:45 2015 marc brout
** Last update Tue Dec  1 14:20:01 2015 marc brout
*/

#include <stdlib.h>

char	*my_realloc(char *str, int size)
{
  char  *tmp;
  int	i;

  if (size == 0)
    {
      if (str != NULL)
	free(str);
      return (NULL);
    }
  if ((tmp = malloc(size + 1)) == NULL)
    return (NULL);
  i = 0;
  while (str[i] && i < size)
    {
      tmp[i] = str[i];
      i += 1;
    }
  while (i < size)
    tmp[i++] = 0;
  tmp[size] = 0;
  if (str != NULL)
    free(str);
  return (tmp);
}
