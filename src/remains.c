/*
** remains.c for bsq
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Tue Dec  1 10:45:57 2015 marc brout
** Last update Wed Dec 16 17:09:57 2015 marc brout
*/

#include "../include/bsq.h"

int	my_errors(t_map *map, int err)
{
  if (err)
    {
      if (err == 1)
	write(2, "File can't be opened\n",22);
      if (err == 2)
	{
	  write(2, "Map corrupted\n", 15);
	  free(map->tmap);
	  free(map->treal);
	}
      if (err == 3)
	write(2, "First line missing\n", 20);
      return (1);
    }
  return (0);
}

int	open_file(t_map *map, char *path)
{
  int	fd;
  char	buff[2];
  int	i;

  if ((fd = open(path, O_RDONLY)) == -1)
    return (1);
  if (read_map_height(map, fd, buff) || build_tab(map))
    return (3);
  i = 0;
  if (((map->treal[i] = read_map_first_line(map, fd, buff)) == NULL) ||
      ((map->tmap[i] = malloc(sizeof(int) * map->width)) == NULL))
    return (2);
  putline_in_map(map, map->treal[i], i);
  while (++i < map->height)
    {
      if (((map->treal[i] = read_next_lines(fd, map->width)) == NULL) ||
	  ((map->tmap[i] = malloc(sizeof(int) * map->width)) == NULL))
	return (2);
      putline_in_map(map, map->treal[i], i);
    }
  close(fd);
  return (0);
}

void		show_tab(t_map *map)
{
  int		i;

  i = -1;
  while (++i < map->height)
    {
      my_putstr(map->treal[i]);
      my_putchar('\n');
      if (map->treal[i] != NULL)
	free(map->treal[i]);
      if (map->tmap[i] != NULL)
	free(map->tmap[i]);
    }
}

