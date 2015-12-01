/*
** my_putstr.c for my_putstr in /home/brout_m/dev/PJ4
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Thu Oct  1 13:17:19 2015 marc brout
** Last update Tue Dec  1 10:40:23 2015 marc brout
*/

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}
