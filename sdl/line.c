/*
** line.c for  in /Users/cyrilmorales/Documents/luasdl
**
** Made by Cyril Morales
** Login   <morale_c@epitech.net>
**
** Started on  Fri Jun  8 19:20:55 2012 Cyril Morales
** Last update Fri Jun  8 21:44:33 2012 Cyril Morales
*/

#include "sdl.h"
#include "draw.h"

void		sdl_draw_line(SDL_Surface *this, t_line ln, t_color color)
{
  t_pos		pos;

  pos.x = ln.x1;
  while ((pos.x <= ln.x2) && ((ln.x2 - ln.x1) >= abs(ln.y2 - ln.y1)))
    {
      pos.y = ln.y1 + (((ln.y2 - ln.y1) * (pos.x - ln.x1)) / (ln.x2 - ln.x1));
      sdl_draw_pixel(this, sdl_new_pos(pos.x++, pos.y), color);
    }
  while ((pos.x >= ln.x2) && ((ln.x1 - ln.x2) >= abs(ln.y1 - ln.y2)))
    {
      pos.y = ln.y1 + (((ln.y2 - ln.y1) * (pos.x - ln.x1)) / (ln.x2 - ln.x1));
      sdl_draw_pixel(this, sdl_new_pos(pos.x--, pos.y), color);
    }
  pos.y = ln.y1;
  while ((pos.y <= ln.y2) && ((ln.y2 - ln.y1) >= abs(ln.x2 - ln.x1)))
    {
      pos.x = ln.x1 + (((ln.x2 - ln.x1) * (pos.y - ln.y1)) / (ln.y2 - ln.y1));
      sdl_draw_pixel(this, sdl_new_pos(pos.x, pos.y++), color);
    }
  while ((pos.y >= ln.y2) && ((ln.y1 - ln.y2) >= abs(ln.x1 - ln.x2)))
    {
      pos.x = ln.x1 + (((ln.x2 - ln.x1) * (pos.y - ln.y1)) / (ln.y2 - ln.y1));
      sdl_draw_pixel(this, sdl_new_pos(pos.x, pos.y--), color);
    }
}
