/*
** main.c for  in /Users/cyrilmorales/Documents/epitech/209sondage
**
** Made by Cyril Morales
** Login   <morale_c@epitech.net>
**
** Started on  Wed Jun  6 01:30:19 2012 Cyril Morales
** Last update Fri Jun 22 13:10:26 2012 Cyril Morales
*/

#include <unistd.h>
#include <stdlib.h>
#include "sdl/sdl.h"
#include "lua/lua.h"
#include "lsdl.h"

int		main(int argc, char **argv)
{
  t_lua		*lua = new_lua();

  sdl = new_sdl();

  if (argc >= 3)
    sdl->setWindowSize(sdl, atoi(argv[1]), atoi(argv[2]));

  register_functions(lua);

  lua->run(lua, "index.lua");

  lua->free(lua);
  sdl->free(sdl);

  return (EXIT_SUCCESS);
}
