/*
** text.c for  in /Users/cyrilmorales/Documents/luasdl
**
** Made by Cyril Morales
** Login   <morale_c@epitech.net>
**
** Started on  Sat Jun  9 15:47:06 2012 Cyril Morales
** Last update Sat Jun  9 20:14:16 2012 Cyril Morales
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "xfunc.h"
#include "sdl.h"

/* destructor */
static void	sdl_text_free(t_text*);
/* add new font */
static void	sdl_text_add_font(t_ttf *this, char *filename, char *name, int size);
/* delete font by id name */
static int	sdl_text_del_font(t_ttf *this, char *name);
/* delete all fonts */
static void	sdl_text_del_all_fonts(t_ttf *this);
/* getter */
static t_ttf	*sdl_text_get_all_fonts(t_text *this);
static t_ttf	*sdl_text_get_font(t_ttf *this, char *name);

t_text		*new_sdl_text()
{
  t_text       	*this;

  if(TTF_Init() == -1)
    {
      fprintf(stderr, "new_sdl_text(): unable to initialize TTF_Init : %s\n", TTF_GetError());
      exit(EXIT_FAILURE);
    }
  this = xmalloc(sizeof(struct s_text));
  this->free = sdl_text_free;
  this->addFont = sdl_text_add_font;
  this->delFont = sdl_text_del_font;
  this->delAllFonts = sdl_text_del_all_fonts;

  this->getAllFonts = sdl_text_get_all_fonts;
  this->getFont = sdl_text_get_font;

  this->fonts_ = NULL;

  return (this);
}

static void	sdl_text_free(t_text *this)
{
  this->delAllFonts(this->fonts_);

  TTF_Quit();

  xfree(this);
}

static void	sdl_text_add_font(t_ttf *this, char *filename, char *name, int size)
{
  t_ttf		*tmp;
  t_ttf		*new;

  tmp = this;
  new = xmalloc(sizeof(struct s_ttf));
  new->name_ = name;
  new->size_ = size;
  new->font_ = TTF_OpenFont(filename, size);
  if (new->font_ == NULL)
    {
      fprintf(stderr, "sdl_text_add_font() : %s\n", TTF_GetError());
      exit(EXIT_FAILURE);
    }
  new->next = NULL;
  if (tmp == NULL)
    tmp = new;
  else
    {
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = new;
    }
}

static int	sdl_text_del_font(t_ttf *this, char *name)
{
  t_ttf		*tmp;

  tmp = this;
  while (tmp != NULL)
    {
      if (strcmp(tmp->name_, name) == 0)
	{
	  xfree(tmp->name_);
	  if (tmp->font_ != NULL)
	    TTF_CloseFont(tmp->font_);
	  return (0);
	}
    }
  return (-1);
}

static void	sdl_text_del_all_fonts(t_ttf *this)
{
  t_ttf		*tmp;

  tmp = this;
  while (tmp != NULL)
    {
      xfree(tmp->name_);
      if (tmp->font_ != NULL)
	TTF_CloseFont(tmp->font_);
      tmp = tmp->next;
      this = tmp;
      xfree(this);
    }
  this = NULL;
}

static t_ttf	*sdl_text_get_font(t_ttf *this, char *name)
{
  t_ttf		*tmp;

  tmp = this;
  while (tmp != NULL)
    {
      if (strcmp(tmp->name_, name) == 0 && tmp->font_ != NULL)
	return (tmp);
    }
  return (NULL);
}

static t_ttf	*sdl_text_get_all_fonts(t_text *this)
{
  return (this->fonts_);
}
