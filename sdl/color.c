/*
** color.c<2> for  in /Users/cyrilmorales/Documents/luasdl
**
** Made by Cyril Morales
** Login   <morale_c@epitech.net>
**
** Started on  Fri Jun  8 18:32:52 2012 Cyril Morales
** Last update Fri Jun  8 20:13:27 2012 Cyril Morales
*/

#include "sdl.h"

t_color		sdl_new_rgb_color(int r, int g, int b)
{
  t_color      	color;

  color.r = 0;
  color.g = 0;
  color.b = 0;

  if (r >= 0 && r < 256)
    color.r = r;
  if (g >= 0 && g < 256)
    color.g = g;
  if (b >= 0 && b < 256)
    color.b = b;

  return (color);
}
