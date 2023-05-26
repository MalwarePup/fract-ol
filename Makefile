# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/26 13:05:47 by ladloff           #+#    #+#              #
#    Updated: 2023/05/26 20:16:11 by ladloff          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				:=	fractol

SRC_PATH			:=	./src
BUILD_PATH			:=	./build
INCLUDE_PATH		:=	./include
LIBFT_PATH			:=	./lib/libft
LIBMLX_PATH			:=	./lib/minilibx-linux

SRC_PATH_FILES		:=	fractol.c \
						mlx.c \
						hook.c \
						render.c \
						sets_of_fractal/mandelbrot.c \
						sets_of_fractal/julia.c
OBJ_FILES			:=	$(patsubst %.c,$(BUILD_PATH)/%.o,$(SRC_PATH_FILES))
INCLUDE_PATH_FLAGS	:=	-I $(INCLUDE_PATH) -I $(LIBFT_PATH)/include \
						-I $(LIBMLX_PATH)

ifeq ($(shell uname -s),Linux)
	CFLAGS			:=	-Wall -Wextra -Werror -g3 $(INCLUDE_PATH_FLAGS)
	LDFLAGS			:=	-L$(LIBFT_PATH) -L$(LIBMLX_PATH)
	LDLIBS			:=	-lft -lmlx_Linux -lXext -lX11
else
	$(error Unsupported operating system)
endif
# else ifeq ($(shell uname -s),Darwin)
# 	CFLAGS			:=	-Wall -Wextra -Werror -O3 $(INCLUDE_PATH_FLAGS)
# 	LDFLAGS			:=	-L$(LIBFT_PATH) -L$(LIBMLX_PATH)/build \
# 						-L"/opt/homebrew/Cellar/glfw/3.3.8/lib/"
# 	LDLIBS			:=	-lft -lmlx42 -lglfw \
# 						-framework Cocoa -framework OpenGL -framework IOKit


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
