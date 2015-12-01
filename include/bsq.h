/*
** bsq.h for bsq
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Mon Nov 30 11:56:22 2015 marc brout
** Last update Tue Dec  1 00:59:30 2015 marc brout
*/

#ifndef BSQ_H_
# define BSQ_H_

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "my.h"

typedef struct		s_map
{
  int			**tmap;
  char			**treal;
  int			width;
  int			height;
  int			max;
  int			xmax;
  int			ymax;
}			t_map;

int compare(t_map *, int, int);
void set_max(t_map *, int, int, int);
void putline_in_map(t_map *, char *, int);
void transform(t_map *);
void show_tab(t_map *);
void open_file(t_map *, char *);
void read_map_height(t_map *, int, char *);
char *read_map_first_line(t_map *, int, char *);
char *read_next_lines(int, int);
int build_tab(t_map *);

#endif
