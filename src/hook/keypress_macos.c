/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_macos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:43:20 by ladloff           #+#    #+#             */
/*   Updated: 2023/06/20 12:15:07 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef __APPLE__

# include <stdlib.h>
# include "fractol_hook.h"
# include "fractol_mlx.h"
# include "fractol_render.h"
# include "fractol_color.h"

typedef enum e_apple_key
{
	APPLE_KEY_A = 0,
	APPLE_KEY_S = 1,
	APPLE_KEY_D = 2,
	APPLE_KEY_Q = 12,
	APPLE_KEY_W = 13,
	APPLE_KEY_E = 14,
	APPLE_KEY_R = 15,
	APPLE_KEY_RIGHT_BRACKET = 30,
	APPLE_KEY_LEFT_BRACKET = 33,
	APPLE_KEY_SPACE = 49,
	APPLE_KEY_ESCAPE = 53,
	APPLE_KEY_LEFT = 123,
	APPLE_KEY_RIGHT = 124,
	APPLE_KEY_DOWN = 125,
	APPLE_KEY_UP = 126,
}	t_apple_key;

void	hook_movement(int key, t_mlx *mlx)
{
	if (key == APPLE_KEY_W || key == APPLE_KEY_UP)
		move_up(mlx);
	else if (key == APPLE_KEY_A || key == APPLE_KEY_LEFT)
		move_left(mlx);
	else if (key == APPLE_KEY_S || key == APPLE_KEY_DOWN)
		move_down(mlx);
	else if (key == APPLE_KEY_D || key == APPLE_KEY_RIGHT)
		move_right(mlx);
}

static void	hook_other_options(int key, t_mlx *mlx)
{
	if (key == APPLE_KEY_RIGHT_BRACKET)
	{
		mlx->data.max_iter++;
		render_fractal(mlx);
	}
	else if (key == APPLE_KEY_LEFT_BRACKET)
	{
		if (mlx->data.max_iter > 1)
		{
			mlx->data.max_iter--;
			render_fractal(mlx);
		}
	}
	else if (key == APPLE_KEY_Q)
	{
		zoom(mlx, SCROLL_UP, mlx->data.c);
		render_fractal(mlx);
	}
	else if (key == APPLE_KEY_E)
	{
		zoom(mlx, SCROLL_DOWN, mlx->data.c);
		render_fractal(mlx);
	}
}

int	hook_keypress(int key, t_mlx *mlx)
{
	if (key == APPLE_KEY_ESCAPE)
	{
		cleanup_mlx(mlx);
		exit(EXIT_SUCCESS);
	}
	else if (key == APPLE_KEY_R)
	{
		initialize_data(&mlx->data);
		render_fractal(mlx);
	}
	else if (key == APPLE_KEY_SPACE)
	{
		mlx->data.color_shift = pseudo_rand(mlx->data.color_shift) % 256;
		mlx->data.color_seed = mlx->data.color_shift;
		render_fractal(mlx);
	}
	hook_other_options(key, mlx);
	hook_movement(key, mlx);
	return (EXIT_SUCCESS);
}

#endif
