# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/26 13:05:47 by ladloff           #+#    #+#              #
#    Updated: 2023/05/29 01:22:59 by ladloff          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				:=	fractol

SRC_PATH			:=	./src
BUILD_PATH			:=	./build
INCLUDE_PATH		:=	./include
LIBFT_PATH			:=	./lib/libft
LIBMLX_PATH			:=	./lib/minilibx-linux

SRC_PATH_FILES		:=	fractol.c \
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
INCLUDE_PATH_FLAGS	:=	-I$(INCLUDE_PATH) -I$(LIBFT_PATH)/include

ifeq ($(shell uname -s),Linux)
	CFLAGS			:=	-Wall -Wextra -Werror -O3 $(INCLUDE_PATH_FLAGS) \
						-I $(LIBMLX_PATH)
	LDFLAGS			:=	-L$(LIBFT_PATH) -L$(LIBMLX_PATH)
	LDLIBS			:=	-lft -lmlx_Linux -lXext -lX11 -lm
else ifeq ($(shell uname -s),Darwin)
	LIBMLX_PATH		:=	./lib/minilibx-opengl
	CFLAGS			:=	-Wall -Wextra -Werror -O3 $(INCLUDE_PATH_FLAGS) \
						-I$(LIBMLX_PATH)
	LDFLAGS			:=	-L$(LIBFT_PATH) -L$(LIBMLX_PATH)
	LDLIBS			:=	-lft -lmlx -framework OpenGL -framework AppKit -lm

else
	$(error Unsupported operating system)
endif

all: libmlx libft $(NAME)

libmlx:
	$(MAKE) -C $(LIBMLX_PATH)

libft:
	$(MAKE) -C $(LIBFT_PATH)

$(BUILD_PATH)/%.o: $(SRC_PATH)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(LDFLAGS) $(LDLIBS) -o $(NAME)

clean:
	$(RM) $(OBJ_FILES)
	rm -rf $(BUILD_PATH)
	$(MAKE) clean -C $(LIBMLX_PATH)
	$(MAKE) clean -C $(LIBFT_PATH)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all clean fclean re libft libmlx
