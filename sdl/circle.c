/*
** circle.c for  in /Users/cyrilmorales/Documents/luasdl
**
** Made by Cyril Morales
** Login   <morale_c@epitech.net>
**
** Started on  Fri Jun  8 21:26:11 2012 Cyril Morales
** Last update Fri Jun  8 22:39:39 2012 Cyril Morales
*/

#include "sdl.h"
#include "draw.h"

void		sdl_draw_circle(SDL_Surface *this, t_pos pos, int r, t_color color)
{
  double	error;
  t_pos		mov;
  double       	cx;
  double	cy;

  error = (double)-r;
  mov = sdl_new_pos((double)r - 0.5, (double)0.5);
  cx = pos.x - 0.5;
  cy = pos.y - 0.5;

  while (mov.x >= mov.y)
    {
      sdl_draw_pixel(this, sdl_new_pos((int)(cx + mov.x), (int)(cy + mov.y)), color);
      sdl_draw_pixel(this, sdl_new_pos((int)(cx + mov.y), (int)(cy + mov.x)), color);
      if (mov.x != 0)
	{
	  sdl_draw_pixel(this, sdl_new_pos((int)(cx - mov.x), (int)(cy + mov.y)), color);
	  sdl_draw_pixel(this, sdl_new_pos((int)(cx + mov.y), (int)(cy - mov.x)), color);
	}
      if (mov.y != 0)
	{
	  sdl_draw_pixel(this, sdl_new_pos((int)(cx + mov.x), (int)(cy - mov.y)), color);
	  sdl_draw_pixel(this, sdl_new_pos((int)(cx - mov.y), (int)(cy + mov.x)), color);
	}
      if (mov.x != 0 && mov.y != 0)
	{
	  sdl_draw_pixel(this, sdl_new_pos((int)(cx - mov.x), (int)(cy - mov.y)), color);
	  sdl_draw_pixel(this, sdl_new_pos((int)(cx - mov.y), (int)(cy - mov.x)), color);
	}
      error += mov.y;
      mov.y++;
      error += mov.y;
      if (error >= 0)
	{
	  mov.x--;
	  error -= mov.x;
	  error -= mov.x;
	}
    }
}
