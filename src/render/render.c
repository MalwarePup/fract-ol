/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:12:01 by ladloff           #+#    #+#             */
/*   Updated: 2023/06/15 16:49:34 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol_render.h"
#include "fractol_sets.h"
#include "fractol_color.h"

static void	put_pixel(t_mlx *mlx, int x, int y, t_rgb_color color)
{
	char	*pixel_addr;

	pixel_addr = mlx->addr + x * (mlx->bpp / 8) + y * mlx->size_line;
	*(t_rgb_color *)pixel_addr = color;
}

void	map_pixel_to_complex(t_complex *c, int x, int y, t_mlx *mlx)
{
	c->real = (double)x / WIDTH * (mlx->data.x_max - mlx->data.x_min) + mlx->data.x_min;
	c->imaginary = (double)y / (double)HEIGHT
		* (mlx->data.y_max - mlx->data.y_min) + mlx->data.y_min;
}

static void	set_to_calculate(t_mlx *mlx)
{
	if (mlx->data.set == S_MANDELBROT)
		mandelbrot(mlx->data.c, &mlx->data.iter, mlx->data.max_iter);
	else if (mlx->data.set == S_JULIA)
		julia(&mlx->data.z, mlx->data.c, &mlx->data.iter,
			mlx->data.max_iter);
	else if (mlx->data.set == S_BURNING_SHIP)
		burning_ship(mlx->data.c, &mlx->data.iter, mlx->data.max_iter);
}

void	render_fractal(t_mlx *mlx)
{
	int		x;
	int		y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			if (mlx->data.set == S_JULIA)
				map_pixel_to_complex(&mlx->data.z, x, y, mlx);
			else
				map_pixel_to_complex(&mlx->data.c, x, y, mlx);
			mlx->data.iter = 0;
			set_to_calculate(mlx);
			put_pixel(mlx, x, y, get_color(mlx->data.iter,
					mlx->data.color_seed));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
