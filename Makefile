# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/26 13:05:47 by ladloff           #+#    #+#              #
#    Updated: 2023/06/15 16:24:59 by ladloff          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL				:=	/bin/sh

NAME				:=	fractol

SRC_PATH			:=	./src
BUILD_PATH			:=	./build
INCLUDE_PATH		:=	./include
LIBFT_PATH			:=	./lib/libft
LIBMLX_PATH			:=	./lib/minilibx-linux

SRC_PATH_FILES		:=	main.c \
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
OBJ_FILES			:=	$(patsubst %.c,$(BUILD_PATH)/%.o,$(SRC_PATH_FILES))

ifeq ($(shell uname -s),Linux)
	CFLAGS			:=	-Wall -Wextra -Werror -MMD -MP -O3
	CPPFLAGS		:=	-I$(INCLUDE_PATH) -I$(LIBFT_PATH)/include \
						-I$(LIBMLX_PATH)
	LDFLAGS			:=	-L$(LIBFT_PATH) -L$(LIBMLX_PATH)
	LDLIBS			:=	-lft -lmlx_Linux -lXext -lX11 -lm
else ifeq ($(shell uname -s),Darwin)
	LIBMLX_PATH		:=	./lib/minilibx-opengl
	CFLAGS			:=	-Wall -Wextra -Werror -MMD -MP -O3
	CPPFLAGS		:=	-I$(INCLUDE_PATH) -I$(LIBFT_PATH)/include \
						-I$(LIBMLX_PATH)
	LDFLAGS			:=	-L$(LIBFT_PATH) -L$(LIBMLX_PATH)
	LDLIBS			:=	-lft -lmlx -framework OpenGL -framework AppKit -lm
else
	$(error Unsupported operating system)
endif

.PHONY: all clean fclean re lib cleanlib fcleanlib relib

all: lib $(NAME)

$(BUILD_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

-include $(OBJ_FILES:.o=.d)

$(NAME): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) $(LDFLAGS) $(LDLIBS) -o $(NAME)

lib:
	$(MAKE) -C $(LIBFT_PATH)
	$(MAKE) -C $(LIBMLX_PATH)

clean:
	rm -rf $(BUILD_PATH)

fclean: clean
	$(RM) $(NAME)

re: fclean all

cleanlib:
	$(MAKE) clean -C $(LIBFT_PATH)
	$(MAKE) clean -C $(LIBMLX_PATH)

fcleanlib:
	$(MAKE) fclean -C $(LIBFT_PATH)

relib: fcleanlib lib
