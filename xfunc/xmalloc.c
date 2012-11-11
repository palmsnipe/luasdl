/*
** xmalloc.c for  in /Users/cyrilmorales/Documents/luasdl/xfunc
**
** Made by Cyril Morales
** Login   <morale_c@epitech.net>
**
** Started on  Thu Jun  7 03:52:19 2012 Cyril Morales
** Last update Thu Jun  7 03:52:56 2012 Cyril Morales
*/

#include <stdio.h>
#include <stdlib.h>
#include "xfunc.h"

void		*xmalloc(size_t size)
{
  void		*ptr;

  if ((ptr = malloc(size)) == NULL)
    {
      perror("malloc()");
      exit (EXIT_FAILURE);
    }

  return (ptr);
}
