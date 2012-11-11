/*
** draw.h for  in /Users/cyrilmorales/Documents/luasdl
**
** Made by Cyril Morales
** Login   <morale_c@epitech.net>
**
** Started on  Fri Jun  8 19:01:01 2012 Cyril Morales
** Last update Fri Jun  8 21:54:27 2012 Cyril Morales
*/

#ifndef __DRAW_H__
#define __DRAW_H__

/* pixel.c */
int		sdl_draw_pixel(SDL_Surface *this, t_pos pos, t_color color);
/* line.c */
void		sdl_draw_line(SDL_Surface *this, t_line ln, t_color color);
/* circle.c */
void		sdl_draw_circle(SDL_Surface *this, t_pos pos, int r, t_color color);

#endif
