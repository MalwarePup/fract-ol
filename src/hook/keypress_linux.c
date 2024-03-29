/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_linux.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:43:20 by ladloff           #+#    #+#             */
/*   Updated: 2023/07/30 10:46:20 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef __linux__

# include <stdlib.h>
# include "fractol_hook.h"
# include "fractol_mlx.h"
# include "fractol_render.h"
# include "fractol_color.h"

static void	hook_movement(int key, t_mlx *mlx)
{
	if (key == XK_w || key == XK_W || key == XK_Up)
		move_up(mlx);
	else if (key == XK_a || key == XK_A || key == XK_Left)
		move_left(mlx);
	else if (key == XK_s || key == XK_S || key == XK_Down)
		move_down(mlx);
	else if (key == XK_d || key == XK_D || key == XK_Right)
		move_right(mlx);
}

static void	hook_other_options(int key, t_mlx *mlx)
{
	if (key == XK_bracketright)
	{
		mlx->data.max_iter++;
		render_fractal(mlx);
	}
	else if (key == XK_bracketleft)
	{
		if (mlx->data.max_iter > 1)
		{
			mlx->data.max_iter--;
			render_fractal(mlx);
		}
	}
	else if (key == XK_q || key == XK_Q)
	{
		zoom(mlx, SCROLL_UP, mlx->data.c);
		render_fractal(mlx);
	}
	else if (key == XK_e || key == XK_E)
	{
		zoom(mlx, SCROLL_DOWN, mlx->data.c);
		render_fractal(mlx);
	}
}

int	hook_keypress(int key, t_mlx *mlx)
{
	if (key == XK_Escape)
	{
		cleanup_mlx(mlx);
		exit(EXIT_SUCCESS);
	}
	else if (key == XK_R || key == XK_r)
	{
		initialize_data(&mlx->data, mlx);
		render_fractal(mlx);
	}
	else if (key == XK_space)
	{
		mlx->data.color_shift = get_secure_random_uint32(mlx) % 256;
		render_fractal(mlx);
	}
	hook_other_options(key, mlx);
	hook_movement(key, mlx);
	return (EXIT_SUCCESS);
}

#endif
