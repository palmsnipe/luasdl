/*
** window.c for  in /Users/cyrilmorales/Documents/luasdl
**
** Made by Cyril Morales
** Login   <morale_c@epitech.net>
**
** Started on  Fri Jun  8 22:59:34 2012 Cyril Morales
** Last update Fri Jun  8 23:00:56 2012 Cyril Morales
*/

#include "sdl.h"
#include "window.h"

void		sdl_set_window_size(t_sdl *this, int width, int height)
{
  this->screen_ = SDL_SetVideoMode(width, height, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  if (this->screen_ == NULL)
    {
      fprintf(stderr, "sdl_set_window_size() : %s\n", SDL_GetError());
    }
}

void		sdl_set_title(t_sdl *this, char *title)
{
  this->title_ = title;
  SDL_WM_SetCaption(title, NULL);
}
