/*
** position.c for  in /Users/cyrilmorales/Documents/luasdl
**
** Made by Cyril Morales
** Login   <morale_c@epitech.net>
**
** Started on  Fri Jun  8 20:08:02 2012 Cyril Morales
** Last update Fri Jun  8 20:52:12 2012 Cyril Morales
*/

#include "sdl.h"

t_pos		sdl_new_pos(int x, int y)
{
  t_pos		pos;

  pos.x = x;
  pos.y = y;

  return (pos);
}

t_line		sdl_new_line(int x1, int y1, int x2, int y2)
{
  t_line       	line;

  line.x1 = x1;
  line.y1 = y1;
  line.x2 = x2;
  line.y2 = y2;

  return (line);
}
