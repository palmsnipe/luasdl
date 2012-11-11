/*
** sdl.h for  in /Users/cyrilmorales/Documents/luasdl
**
** Made by Cyril Morales
** Login   <morale_c@epitech.net>
**
** Started on  Thu Jun  7 01:06:27 2012 Cyril Morales
** Last update Sat Jun  9 18:23:45 2012 Cyril Morales
*/

#ifndef __SDL_H__
#define __SDL_H__

#include <SDL/SDL.h>
#include "text.h"

#define WIDTH	300
#define HEIGHT	300

typedef struct	s_color
{
  unsigned char	r;
  unsigned char	g;
  unsigned char	b;
}		t_color;

typedef struct	s_pos
{
  double       	x;
  double       	y;
}		t_pos;

typedef struct	s_line
{
  double       	x1;
  double       	y1;
  double       	x2;
  double       	y2;
}		t_line;

typedef struct	s_sdl
{
  void       	(*free)(struct s_sdl*);

  void		(*setWindowSize)(struct s_sdl*, int, int);
  void		(*setTitle)(struct s_sdl*, char*);
  void		(*stop)(struct s_sdl*);

  int		(*getRun)(struct s_sdl*);
  SDL_Surface*	(*getScreen)(struct s_sdl*);
  t_text*	(*getText)(struct s_sdl*);

  int		(*drawPixel)(SDL_Surface*, struct s_pos, struct s_color);
  void		(*drawLine)(SDL_Surface*, struct s_line, struct s_color);
  void		(*drawCircle)(SDL_Surface*, struct s_pos, int, struct s_color);

  SDL_Event	event_;
  SDL_Surface	*screen_;
  t_text	*text_;

  char		*title_;
  int		run_;
}		t_sdl;

/* constructor */
t_sdl		*new_sdl();
/* color.c */
t_color		sdl_new_rgb_color(int r, int g, int b);

/* position.c */
t_pos		sdl_new_pos(int x, int y);
t_line		sdl_new_line(int x1, int y1, int x2, int y2);

#endif
