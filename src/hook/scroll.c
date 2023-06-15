/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scroll.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 23:17:41 by ladloff           #+#    #+#             */
/*   Updated: 2023/06/14 18:31:55 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fractol_hook.h"
#include "fractol_render.h"

void	zoom(t_mlx *mlx, int button, t_complex mouse)
{
	double	zoom_factor;

	zoom_factor = 0.0;
	if (button == SCROLL_UP)
	{
		zoom_factor = 1 / ZOOM_SCALING_FACTOR;
		mlx->data.max_iter++;
	}
	if (button == SCROLL_DOWN)
	{
		zoom_factor = ZOOM_SCALING_FACTOR;
		if (mlx->data.max_iter > 40)
			mlx->data.max_iter--;
	}
	mlx->data.x_min = mouse.real + (mlx->data.x_min - mouse.real) * zoom_factor;
	mlx->data.y_min = mouse.imaginary + (mlx->data.y_min - mouse.imaginary)
		* zoom_factor;
	mlx->data.x_max = mouse.real + (mlx->data.x_max - mouse.real) * zoom_factor;
	mlx->data.y_max = mouse.imaginary + (mlx->data.y_max - mouse.imaginary)
		* zoom_factor;
	render_fractal(mlx);
}

int	hook_mouse_scroll(int button, int x, int y, t_mlx *mlx)
{
	t_complex	mouse;

	mouse.real = 0.0;
	mouse.imaginary = 0.0;
	map_pixel_to_complex(&mouse, x, y, mlx);
	if (button == SCROLL_UP || button == SCROLL_DOWN)
		zoom(mlx, button, mouse);
	return (EXIT_SUCCESS);
}
