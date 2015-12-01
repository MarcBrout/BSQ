/*
** remains.c for bsq
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Tue Dec  1 10:45:57 2015 marc brout
** Last update Tue Dec  1 10:47:26 2015 marc brout
*/

#include "../include/bsq.h"

void	open_file(t_map *map, char *path)
{
  int	fd;
  char	buff[2];
  int	i;

  if ((fd = open(path, O_RDONLY)) == -1)
    return ;
  read_map_height(map, fd, buff);
  build_tab(map);
  i = 0;
  map->treal[i] = read_map_first_line(map, fd, buff);
  if ((map->tmap[i] = malloc(sizeof(int) * map->width)) == NULL)
    return ;
  putline_in_map(map, map->treal[i], i);
  while (++i < map->height)
    {
      map->treal[i] = read_next_lines(fd, map->width);
      if ((map->tmap[i] = malloc(sizeof(int) * map->width)) == NULL)
	return ;
      putline_in_map(map, map->treal[i], i);
    }
  close(fd);
}

void		show_tab(t_map *map)
{
  int		i;

  i = -1;
  while (++i < map->height)
    {
      my_putstr(map->treal[i]);
      my_putchar('\n');
      free(map->treal[i]);
      free(map->tmap[i]);
    }
}

