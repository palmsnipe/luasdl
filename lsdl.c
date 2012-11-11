/*
** lsdl.c for  in /Users/cyrilmorales/Documents/luasdl
**
** Made by Cyril Morales
** Login   <morale_c@epitech.net>
**
** Started on  Thu Jun  7 03:55:35 2012 Cyril Morales
** Last update Sat Jun  9 20:08:48 2012 Cyril Morales
*/

#include <unistd.h>
#include <stdlib.h>
#include "sdl/sdl.h"
#include "lua/lua.h"
#include "lsdl.h"

int		lsdl_set_window_size(lua_State* L)
{
  int		nb;
  int		width;
  int		height;

  nb = lua_gettop(L);
  if (nb != 2)
    {
      printf("lsdl_set_window_size() : wrong parameters\n");
      return (0);
    }
  if (!lua_isnumber(L,1) && !lua_isnumber(L,2))
    {
      printf("lsdl_set_window_size() : wrong types\n");
      return (0);
    }
  width = lua_tonumber(L,1);
  height = lua_tonumber(L,2);

  sdl->setWindowSize(sdl, width, height);
  SDL_Flip(sdl->getScreen(sdl));

  return (0);
}

int		lsdl_set_window_title(lua_State* L)
{
  char		*title;
  int		nb;

  nb = lua_gettop(L);
  if (nb != 1)
    {
      printf("lsdl_set_window_title() : wrong parameter\n");
      return (0);
    }
  if (!lua_isstring(L, 1))
    {
      printf("lsdl_set_window_title() : parameter is not a string\n");
      return (0);
    }
  title = (char*)lua_tostring(L, 1);

  sdl->setTitle(sdl, title);

  return (0);
}

int		lsdl_sleep(lua_State* L)
{
  int		nb;
  useconds_t   	ms;

  nb = lua_gettop(L);
  if (nb != 1)
    {
      printf("sleep() : wrong parameter\n");
      return (0);
    }
  if (!lua_isnumber(L,1))
    {
      printf("sleep() : wrong type\n");
      return (0);
    }
  ms = lua_tonumber(L,1);

  usleep(ms);

  return (0);
}

int		lsdl_run(lua_State* L)
{
  int		nb;

  nb = lua_gettop(L);
  if (nb != 0)
    {
      fprintf(stderr, "run() : arguments are found");
      return (0);
    }
  lua_pushnumber(L, sdl->getRun(sdl));

  return (1);
}

int		lsdl_update(lua_State* L)
{
  int		nb;

  nb = lua_gettop(L);
  if (nb != 0)
    fprintf(stderr, "update() : arguments are found");
  else
    SDL_Flip(sdl->getScreen(sdl));

  return (0);
}

int		lsdl_quit(lua_State* L)
{
  int		nb;

  nb = lua_gettop(L);
  if (nb != 0)
    fprintf(stderr, "quit() : arguments are found");
  else
    sdl->stop(sdl);

  return (0);
}

int		lsdl_waitevent(lua_State* L)
{
  int		nb;

  nb = lua_gettop(L);
  if (nb != 0)
    {
      fprintf(stderr, "waitevent() : arguments are found");
      return (0);
    }

  SDL_WaitEvent(&(sdl->event_));

  if (sdl->event_.type == SDL_QUIT)
    sdl->stop(sdl);
  else if (sdl->event_.type == SDL_KEYDOWN)
    {
      if (sdl->event_.key.keysym.sym == SDLK_ESCAPE)
	sdl->stop(sdl);
    }
  SDL_Flip(sdl->getScreen(sdl));

  return (0);
}

int		lsdl_draw_pixel(lua_State* L)
{
  t_pos		pos;
  t_color      	color;
  int		nb;

  nb = lua_gettop(L);
  if (nb != 5)
    {
      fprintf(stderr, "point() : wrong parameters\n");
      return (0);
    }
  if (!lua_isnumber(L, 1) && !lua_isnumber(L, 2) && !lua_isnumber(L, 3)
      && !lua_isnumber(L, 4) && !lua_isnumber(L, 5))
    {
      fprintf(stderr, "point() : one or more parameters are not valid\n");
      return (0);
    }

  pos = sdl_new_pos(lua_tonumber(L, 1), lua_tonumber(L, 2));
  color = sdl_new_rgb_color(lua_tonumber(L, 3),
			    lua_tonumber(L, 4),
			    lua_tonumber(L, 5));

  if (sdl->drawPixel(sdl->getScreen(sdl), pos, color) == -1)
      fprintf(stderr, "point() : pixel not drawn. Invalid coordinates\n");

  return (0);
}

int		lsdl_draw_line(lua_State* L)
{
  t_line       	line;
  t_color      	color;
  int		nb;

  nb = lua_gettop(L);
  if (nb != 7)
    {
      fprintf(stderr, "line() : wrong parameters\n");
      return (0);
    }
  if (!lua_isnumber(L, 1) && !lua_isnumber(L, 2) && !lua_isnumber(L, 3) &&
      !lua_isnumber(L, 4) && !lua_isnumber(L, 5) &&
      !lua_isnumber(L, 6) && !lua_isnumber(L, 7))
    {
      fprintf(stderr, "line() : one or more parameters are not valid\n");
      return (0);
    }

  line = sdl_new_line(lua_tonumber(L, 1), lua_tonumber(L, 2),
		      lua_tonumber(L, 3), lua_tonumber(L, 4));
  color = sdl_new_rgb_color(lua_tonumber(L, 5),
			    lua_tonumber(L, 6),
			    lua_tonumber(L, 7));

  sdl->drawLine(sdl->getScreen(sdl), line, color);

  return (0);
}

int		lsdl_draw_circle(lua_State* L)
{
  t_pos		pos;
  int       	radius;
  t_color      	color;
  int		nb;

  nb = lua_gettop(L);
  if (nb != 6)
    {
      fprintf(stderr, "circle() : wrong parameters\n");
      return (0);
    }
  if (!lua_isnumber(L, 1) && !lua_isnumber(L, 2) && !lua_isnumber(L, 3)
      && !lua_isnumber(L, 4) && !lua_isnumber(L, 5) && !lua_isnumber(L, 6))
    {
      fprintf(stderr, "circle() : one or more parameters are not valid\n");
      return (0);
    }

  pos = sdl_new_pos(lua_tonumber(L, 1), lua_tonumber(L, 2));
  radius = lua_tonumber(L, 3);
  color = sdl_new_rgb_color(lua_tonumber(L, 4),
			    lua_tonumber(L, 5),
			    lua_tonumber(L, 6));

  sdl->drawCircle(sdl->getScreen(sdl), pos, radius, color);

  return (0);
}

int		lsdl_add_font(lua_State* L)
{
  char		*filename;
  char		*name;
  int		size;
  int		nb;

  nb = lua_gettop(L);
  if (nb != 3)
    {
      printf("addFont() : wrong parameter\n");
      return (0);
    }
  if (!lua_isstring(L, 1) && !lua_isstring(L, 2) && !lua_isnumber(L, 3))
    {
      printf("addFont() : one or more parameters are incorrect\n");
      return (0);
    }
  filename = (char*)lua_tostring(L, 1);
  name = (char*)lua_tostring(L, 2);
  size = lua_tonumber(L, 3);

  sdl->getText(sdl)->addFont(sdl->text_->fonts_, filename, name, size);

  return (0);
}

void		register_functions(t_lua *lua)
{
  lua_register(lua->state_, "setWindowSize", lsdl_set_window_size);
  lua_register(lua->state_, "setWindowTitle", lsdl_set_window_title);
  lua_register(lua->state_, "run", lsdl_run);
  lua_register(lua->state_, "update", lsdl_update);
  lua_register(lua->state_, "quit", lsdl_quit);
  lua_register(lua->state_, "usleep", lsdl_sleep);
  lua_register(lua->state_, "waitevent", lsdl_waitevent);

  /* text */
  lua_register(lua->state_, "addFont", lsdl_add_font);

  /* draw */
  lua_register(lua->state_, "point", lsdl_draw_pixel);
  lua_register(lua->state_, "line", lsdl_draw_line);
  lua_register(lua->state_, "circle", lsdl_draw_circle);
}
