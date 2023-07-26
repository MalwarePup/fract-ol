# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/26 13:05:47 by ladloff           #+#    #+#              #
#    Updated: 2023/07/26 06:38:37 by ladloff          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL			:= /bin/sh

NAME			:= fractol

SRC_DIR			:= ./src
BUILD_DIR		:= ./build
INCLUDE_DIR		:= ./include
LIBFT_DIR		:= ./lib/libft
LIBMLX_DIR		:= ./lib/minilibx-linux

SRC_FILES		:= main.c \
					color/color.c \
					error/fractol_error.c \
					hook/event.c \
					hook/hook_manager.c \
					hook/keypress_linux.c \
					hook/keypress_macos.c \
					hook/movement.c \
					hook/scroll.c \
					mlx/mlx_manager.c \
					parser/parser.c \
					render/render.c \
					sets/julia.c \
					sets/mandelbrot.c \
					sets/burning_ship.c

OBJ_FILES		:= $(patsubst %.c,$(BUILD_DIR)/%.o,$(SRC_FILES))

ifeq ($(shell uname -s),Linux)
	CFLAGS		+= -Wall -Wextra -Werror -MMD -MP -O3
	CPPFLAGS	+= -I$(INCLUDE_DIR) -I$(LIBFT_DIR)/include \
					-I$(LIBMLX_DIR)
	LDFLAGS		+= -L$(LIBFT_DIR) -L$(LIBMLX_DIR)
	LDLIBS		+= -lft -lmlx_Linux -lm -lXext -lX11
else ifeq ($(shell uname -s),Darwin)
	LIBMLX_DIR	:= ./lib/minilibx-opengl
	CFLAGS		+= -Wall -Wextra -Werror -MMD -MP -O3
	CPPFLAGS	+= -I$(INCLUDE_DIR) -I$(LIBFT_DIR)/include \
					-I$(LIBMLX_DIR)
	LDFLAGS		+= -L$(LIBFT_DIR) -L$(LIBMLX_DIR)
	LDLIBS		+= -lft -lmlx -lm -framework OpenGL -framework AppKit
else
	$(error Unsupported operating system)
endif

.PHONY: all clean fclean re lib cleanlib fcleanlib relib cleanall fcleanall \
reall

all: lib $(NAME)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

-include $(OBJ_FILES:.o=.d)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(LDFLAGS) $(LDLIBS) -o $(NAME)

lib:
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(LIBMLX_DIR)

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

cleanlib:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(LIBMLX_DIR)

fcleanlib:
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(LIBMLX_DIR)

relib: fcleanlib lib

cleanall: cleanlib clean

fcleanall: fcleanlib fclean

reall: fcleanall all
