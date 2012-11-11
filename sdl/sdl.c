/*
** sdl.c for  in /Users/cyrilmorales/Documents/luasdl
**
** Made by Cyril Morales
** Login   <morale_c@epitech.net>
**
** Started on  Thu Jun  7 01:05:58 2012 Cyril Morales
** Last update Tue Jun 19 12:45:34 2012 Cyril Morales
*/

#include <stdio.h>
#include <stdlib.h>
#include "xfunc.h"
#include "sdl.h"
#include "draw.h"
#include "window.h"

/* destructor */
static void	sdl_free(t_sdl*);

/* quit loop */
static void    	sdl_stop(t_sdl*);
/* getter */
static int		sdl_get_run(t_sdl *this);
static SDL_Surface	*sdl_get_screen(t_sdl *this);
static t_text		*sdl_get_text(t_sdl *this);

t_sdl		*new_sdl()
{
  t_sdl		*this;

  this = xmalloc(sizeof(struct s_sdl));

  this->free = sdl_free;
  this->setWindowSize = sdl_set_window_size;
  this->setTitle = sdl_set_title;
  this->getRun = sdl_get_run;
  this->getText = sdl_get_text;
  this->stop = sdl_stop;
  this->getScreen = sdl_get_screen;
  this->drawPixel = sdl_draw_pixel;
  this->drawLine = sdl_draw_line;
  this->drawCircle = sdl_draw_circle;

  SDL_Init(SDL_INIT_VIDEO);
  this->screen_ = SDL_SetVideoMode(WIDTH, HEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  SDL_FillRect(this->screen_, NULL, SDL_MapRGB(this->screen_->format, 0, 0, 0));
  SDL_Flip(this->screen_);

  this->text_ = new_sdl_text();
  this->run_ = 1;

  return (this);
}

static void	sdl_free(t_sdl *this)
{
  SDL_FreeSurface(this->screen_);
  SDL_Quit();

  this->text_->free(this->text_);

  xfree(this);
}

static SDL_Surface	*sdl_get_screen(t_sdl *this)
{
  return (this->screen_);
}

static t_text	*sdl_get_text(t_sdl *this)
{
  return (this->text_);
}

static int	sdl_get_run(t_sdl *this)
{
  return (this->run_);
}

static void    	sdl_stop(t_sdl *this)
{
  this->run_ = 0;
}
