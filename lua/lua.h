/*
** lua.h for  in /Users/cyrilmorales/Documents/luasdl
**
** Made by Cyril Morales
** Login   <morale_c@epitech.net>
**
** Started on  Thu Jun  7 00:06:25 2012 Cyril Morales
** Last update Fri Jun  8 15:45:09 2012 Cyril Morales
*/

#ifndef __LUA_H__
#define __LUA_H__

#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

typedef struct	s_lua
{
  void       	(*free)(struct s_lua*);
  void       	(*run)(struct s_lua*, char*);

  lua_State  	*state_;

}		t_lua;

/* constructor */
t_lua		*new_lua();

#endif
