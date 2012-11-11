/*
** pixel.c for  in /Users/cyrilmorales/Documents/luasdl
**
** Made by Cyril Morales
** Login   <morale_c@epitech.net>
**
** Started on  Fri Jun  8 18:59:14 2012 Cyril Morales
** Last update Fri Jun  8 21:46:53 2012 Cyril Morales
*/

#include "sdl.h"
#include "draw.h"

int		sdl_draw_pixel(SDL_Surface *this, t_pos pos, t_color color)
{
  const SDL_VideoInfo	*win;
  int		rgb;
  int		*pixel;

  win = SDL_GetVideoInfo();
  if (pos.x >= 0 && pos.y >= 0 && pos.x < win->current_w && pos.y < win->current_h)
    {
      rgb = SDL_MapRGB(this->format, color.r, color.g, color.b);
      pixel = (int *)this->pixels + (int)pos.y * this->pitch / 4 + (int)pos.x;
      *pixel = rgb;
    }
  else
    return (-1);

  return (0);
}
