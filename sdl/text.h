/*
** text.h for  in /Users/cyrilmorales/Documents/luasdl
**
** Made by Cyril Morales
** Login   <morale_c@epitech.net>
**
** Started on  Sat Jun  9 16:40:53 2012 Cyril Morales
** Last update Sat Jun  9 19:52:22 2012 Cyril Morales
*/

#ifndef __TEXT_H__
#define __TEXT_H__

#ifdef __APPLE__
#include <SDL_ttf/SDL_ttf.h>
#else
#include <SDL/SDL_ttf.h>
#endif

typedef struct	s_ttf
{
  char		*name_;
  int		size_;
  TTF_Font	*font_;
  struct s_ttf	*next;
}		t_ttf;

typedef struct	s_text
{
  void       	(*free)(struct s_text*);
  void		(*addFont)(struct s_ttf*, char*, char*, int);
  int		(*delFont)(struct s_ttf*, char*);
  void		(*delAllFonts)(struct s_ttf*);

  t_ttf*	(*getAllFonts)(struct s_text*);
  t_ttf*	(*getFont)(struct s_ttf*, char*);

  t_ttf		*fonts_;
}		t_text;

/* constructor */
t_text		*new_sdl_text();

#endif
