/*
** bsq.c for bsq
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Mon Nov 30 11:54:41 2015 marc brout
** Last update Tue Dec  1 10:47:30 2015 marc brout
*/

#include "../include/bsq.h"

int	build_tab(t_map *map)
{
  if ((map->tmap = malloc(sizeof(int *) * (map->height + 1))) == NULL)
    return (1);
  map->tmap[map->height] = NULL;
  if ((map->treal = malloc(sizeof(char *) * (map->height + 1))) == NULL)
    return (1);
  map->treal[map->height] = NULL;
  map->max = 0;
  map->ymax = 0;
  map->xmax = 0;
  return (0);
}

char	*read_map_first_line(t_map *map, int fd, char *buff)
{
  int	size;
  char	*str;

  if ((str = malloc(2)) == NULL)
    return (NULL);
  if ((map->width = read(fd, buff, 1)) == -1)
    return (NULL);
  str[0] = buff[0];
  str[1] = 0;
  size = 1;
  while ((map->width = read(fd, buff, 1)) && buff[0] != '\n')
    {
      buff[1] = 0;
      size += 1;
      str = my_realloc(str, size);
      my_strcat(str, buff);
    }
  map->width = size;
  return (str);
}

char	*read_next_lines(int fd, int size)
{
  int	l;
  char  *buff;
  char	*str;
  int	i;

  if ((buff = malloc(size + 2)) == NULL)
    return (NULL);
  if ((str = malloc(size + 1)) == NULL)
    return (NULL);
  if ((l = read(fd, buff, size + 1)) == -1)
    return (NULL);
  buff[size + 1] = 0;
  i = 0;
  while (buff[i])
    {
      str[i] = buff[i];
      i += 1;
    }
  str[size] = 0;
  free(buff);
  return (str);
}

void	read_map_height(t_map *map, int fd, char *buff)
{
  int	size;
  char	*height;

  if ((height = malloc(1)) == NULL)
    return ;
  height[0] = 0;
  size = 1;
  while ((map->height = read(fd, buff, 1)) && buff[0] != '\n')
    {
      buff[1] = 0;
      size += 1;
      height = my_realloc(height, size);
      my_strcat(height, buff);
    }
  map->height = my_getnbr(height);
  free(height);
}

int		main(int ac, char **av)
{
  t_map		map;

  if (ac < 2)
    return (1);
  open_file(&map, av[1]);
  transform(&map);
  show_tab(&map);
  free(map.tmap);
  free(map.treal);
  return (0);
}
