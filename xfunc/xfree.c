/*
** xfree.c for  in /Users/cyrilmorales/Documents/luasdl/xfunc
**
** Made by Cyril Morales
** Login   <morale_c@epitech.net>
**
** Started on  Thu Jun  7 03:53:23 2012 Cyril Morales
** Last update Thu Jun  7 03:53:32 2012 Cyril Morales
*/

#include <stdio.h>
#include <stdlib.h>
#include "xfunc.h"

void		xfree(void *ptr)
{
  if (ptr == NULL)
    {
      fprintf(stderr, "free() : Unable to free. Pointer is NULL\n");
      exit (EXIT_FAILURE);
    }
  else
    free(ptr);
}
