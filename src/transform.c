/*
** transform.c for bsq
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Mon Nov 30 18:44:26 2015 marc brout
** Last update Tue Dec  1 00:07:00 2015 marc brout
*/

#include "../include/bsq.h"

void	putline_in_map(t_map *map, char *str, int i)
{
  int	j;

  j = -1;
  while (++j < map->width)
    {
      map->tmap[i][j] = (str[j] == '.') ? 1 : 0;
      if (map->max != map->width && map->max != map->height
	  && map->tmap[i][j])
	{
	  map->tmap[i][j] += compare(map, i, j);
	  set_max(map, j, i, map->tmap[i][j]);
	}
    }
}

int	compare(t_map *map, int i, int j)
{
  int	top;
  int	left;
  int	diag;
  int	min;

  top = (i == 0) ? 0 : map->tmap[i - 1][j];
  left = (j == 0) ? 0 : map->tmap[i][j - 1];
  diag = (i == 0 || j == 0) ? 0 : map->tmap[i - 1][j - 1];
  min = (top < left) ? top : left;
  min = (diag < min) ? diag : min;
  return (min);
}

void	set_max(t_map *map, int i, int j, int max)
{
  if (max > map->max)
    {
      map->max = max;
      map->ymax = j;
      map->xmax = i;
    }
}

void	transform(t_map *map)
{
  int	i;
  int	j;

  j = map->ymax + 1;
  while (--j > (map->ymax - map->max))
    {
      i = map->xmax + 1;
      while (--i > (map->xmax - map->max))
	map->treal[j][i] = 'x';
    }
}
