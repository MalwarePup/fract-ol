/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:43:20 by ladloff           #+#    #+#             */
/*   Updated: 2023/05/26 23:22:55 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window_event(t_mlx *mlx)
{
	destroy_mlx(mlx);
	exit(EXIT_SUCCESS);
}

int	hook_keypress(int keycode, t_mlx *mlx)
{
	if (keycode == K_ESC)
	{
		destroy_mlx(mlx);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == K_BRACKET_LEFT)
	{
		mlx->data->max_iter++;
		render_fractal(mlx);
	}
	else if (keycode == K_BRACKET_RIGHT)
	{
		if (mlx->data->max_iter > 1)
		{
			mlx->data->max_iter--;
			render_fractal(mlx);
		}
	}
	return (EXIT_SUCCESS);
}

int	hook_mouse_scroll(int button, int x, int y, t_mlx *mlx)
{
	t_complex	mouse;
	double		zoom_factor;

	map_pixel_to_complex(&mouse, x, y, mlx);
	if (button == SCROLL_UP || button == SCROLL_DOWN)
	{
		if (button == SCROLL_UP)
			zoom_factor = SCROLL_SENSITIVITY;
		else
			zoom_factor = 1 / SCROLL_SENSITIVITY;
		mlx->data->x_min = mouse.real
			+ (mlx->data->x_min - mouse.real) * zoom_factor;
		mlx->data->y_min = mouse.imaginary
			+ (mlx->data->y_min - mouse.imaginary) * zoom_factor;
		mlx->data->x_max = mouse.real
			+ (mlx->data->x_max - mouse.real) * zoom_factor;
		mlx->data->y_max = mouse.imaginary
			+ (mlx->data->y_max - mouse.imaginary) * zoom_factor;
		render_fractal(mlx);
	}
	return (0);
}
