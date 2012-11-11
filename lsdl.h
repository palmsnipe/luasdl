/*
** lsdl.h for  in /Users/cyrilmorales/Documents/luasdl
**
** Made by Cyril Morales
** Login   <morale_c@epitech.net>
**
** Started on  Thu Jun  7 03:58:04 2012 Cyril Morales
** Last update Fri Jun  8 21:12:12 2012 Cyril Morales
*/

#ifndef _LSDL_H__
#define _LSDL_H__

t_sdl		*sdl;

/* initialize C functions for lua */
void		register_functions(t_lua *lua);

/* window functions */
int		lsdl_set_window_size(lua_State* L);
int		lsdl_set_window_title(lua_State* L);

/* graphic functions */
int		lsdl_draw_pixel(lua_State* L);
int		lsdl_draw_line(lua_State* L);
int		lsdl_draw_circle(lua_State* L);

#endif
