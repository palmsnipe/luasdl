/*
** lua.c for  in /Users/cyrilmorales/Documents/luasdl
**
** Made by Cyril Morales
** Login   <morale_c@epitech.net>
**
** Started on  Thu Jun  7 00:14:56 2012 Cyril Morales
** Last update Fri Jun  8 15:47:35 2012 Cyril Morales
*/

#include <stdio.h>
#include <stdlib.h>
#include "xfunc.h"
#include "lua.h"

static void    	lua_init(t_lua *this);

/* destructor */
static void    	lua_free(t_lua*);
/* run lua script */
static void   	lua_run(t_lua*, char*);

static void    	lua_init(t_lua *this)
{
  this->run = lua_run;

  this->state_ = luaL_newstate();
  luaL_openlibs(this->state_);
}

t_lua		*new_lua()
{
  t_lua		*this = xmalloc(sizeof(struct s_lua));

  lua_init(this);
  this->free = lua_free;

  return (this);
}

static void   	lua_free(t_lua *this)
{
  xfree(this);
}

static void   	lua_run(t_lua *this, char *filename)
{
  if (luaL_dofile(this->state_, filename) != 0)
    {
      fprintf(stderr, "lua_run() : %s\n", lua_tostring(this->state_, -1));
      exit (EXIT_FAILURE);
    }
}
