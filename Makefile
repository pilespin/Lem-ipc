# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/23 14:06:14 by pilespin          #+#    #+#              #
#    Updated: 2015/10/11 20:38:35 by pilespin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean fclean all

NAME = lemipc
NAME_REMOVE = remove_map
NAME_VISU = visu

SDIR = src/
HDIR = includes/
ODIR = object/
LIB_SDL = libsdl
PATH_SDL = SDL2-2.0.3
SDL_CHECK = $(LIB_SDL)/include/SDL2/SDL.h

SRCA = project.c \
	   check.c \
	   get.c \
	   get_pos.c \
	   create.c \
	   shm.c \
	   signal.c \
	   move.c \
	   move_algo.c \
	   sdl.c \
	   draw.c \

SRCH = project.h \
	   struct.h \

SRCO = $(SRCA:.c=.o)

LIB = -L ./libft/ -lft
INC_SDL = -I./$(LIB_SDL)/include
SDL = `./$(LIB_SDL)/bin/sdl2-config --cflags --libs`
FLAGS = -Wall -Wextra -Werror

SRC = $(patsubst %.c, $(SDIR)%.c, $(SRCA))
HDR = $(patsubst %.h, $(HDIR)%.h, $(SRCH))
OBJ = $(patsubst %.c, $(ODIR)%.o, $(SRCA))

all: sdl $(NAME)

no: $(NAME)

sdl:
	@echo "\033[32mCompiling SDL ...\033[0m" ; make -C ./libft
	@mkdir -p $(LIB_SDL)
	@tar -xf $(PATH_SDL).tar.gz
	@cd $(PATH_SDL) && ./configure --prefix=`cd ../$(LIB_SDL) && pwd` && make && make install

$(NAME): $(OBJ) $(SRC) main_lemipc.c main_visu.c
	@echo "\033[32m compiling libft >>> \c \033[0m" ; make -C ./libft
	@gcc -O3 -o $(NAME) $(INC_SDL) $(OBJ) main_lemipc.c $(LIB)
	@gcc -O3 -o $(NAME_VISU) $(INC_SDL) $(OBJ) main_visu.c sdl2.c $(LIB) $(SDL)
	@echo "\033[37m END $(NAME)\033[0m"

$(ODIR)%.o: $(SDIR)%.c $(HDR)
	@mkdir -p $(ODIR)
	@gcc $(INC_SDL) -c $< -o $@ $(FLAGS)
	@echo "\033[32m ok \033[33m $@\033[0m"

clean:
	@make -C ./libft clean
	@rm -rf $(ODIR)
	@rm -f main_lemipc.o
	@rm -f main_visu.o
	@rm -rf $(PATH_SDL)

fclean: clean
	@make -C ./libft fclean
	@rm -f $(NAME)
	@rm -f $(NAME_VISU)
	@rm -rf $(LIB_SDL)

re: fclean all
