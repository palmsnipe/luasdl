##
## Makefile for  in /Users/cyrilmorales/Documents/epitech/209sondage
## 
## Made by Cyril Morales
## Login   <morale_c@epitech.net>
## 
## Started on  Wed Jun  6 02:05:58 2012 Cyril Morales
## Last update Tue Jul  3 13:23:51 2012 Cyril Morales
##

MACHINE = $(shell uname -s)

NAME = luasdl

CC = gcc

ifeq ($(MACHINE), Darwin)
    SDL_INC =	-I/Library/Frameworks/SDL.framework/Headers \
		-I/Library/Frameworks/SDL_ttf.framework/Headers
    SDL_LIB =	sdl/SDLMain.m -framework SDL -framework SDL_ttf -framework Cocoa
else
    SDL_INC =	`sdl-config --cflags`
    SDL_LIB =	`sdl-config --libs`
endif

CFLAGS += -W -Wall -Werror -g -ggdb -g3 -I/usr/local/include -I./xfunc $(SDL_INC)

LDFLAGS += -L/usr/local/lib -llua $(SDL_LIB)

SRC =	main.c \
	lsdl.c \
	lua/lua.c \
	sdl/sdl.c \
	sdl/text.c \
	sdl/window.c \
	sdl/position.c \
	sdl/pixel.c \
	sdl/line.c \
	sdl/circle.c \
	sdl/color.c \
	xfunc/xmalloc.c \
	xfunc/xfree.c

OBJ = $(SRC:.c=.o)

TMP = $(SRC:.c=.c~)

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
		rm -rf $(OBJ) $(TMP)

fclean:		clean
		rm -rf $(NAME)

re:		fclean all