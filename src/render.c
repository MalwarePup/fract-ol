/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:12:01 by ladloff           #+#    #+#             */
/*   Updated: 2023/05/27 14:45:29 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"

uint32_t	get_color(int iter, int max_iter)
{
	double		t;
	uint32_t	r;
	uint32_t	g;
	uint32_t	b;

	t = (double)iter / (double)max_iter;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((r << 16) | (g << 8) | b);
}

void	map_pixel_to_complex(t_complex *c, int32_t x, int32_t y, t_mlx *mlx)
{
	c->real = (double)x / (double)WIDTH
		* (mlx->data.x_max - mlx->data.x_min) + mlx->data.x_min;
	c->imaginary = (double)y / (double)HEIGHT
		* (mlx->data.y_max - mlx->data.y_min) + mlx->data.y_min;
}

static void	put_pixel(t_mlx *mlx, int32_t x, int32_t y, uint32_t color)
{
	char	*pixel_addr;

	pixel_addr = mlx->addr + (x * (mlx->bits_per_pixel / 8)
			+ y * mlx->size_line);
	*(uint32_t *)pixel_addr = color;
}

void	set_to_render(t_mlx *mlx)
{
	if (mlx->data.set == S_MANDELBROT)
		mandelbrot(mlx->data.c, &mlx->data.iter, mlx->data.max_iter);
	if (mlx->data.set == S_JULIA)
		julia(&mlx->data.z, mlx->data.c, &mlx->data.iter,
			mlx->data.max_iter);
}

void	render_fractal(t_mlx *mlx)
{
	int32_t		x;
	int32_t		y;

	x = 0;
	mlx_clear_window(mlx->mlx, mlx->win);
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
			set_to_render(mlx);
			put_pixel(mlx, x, y, get_color(mlx->data.iter,
					mlx->data.max_iter));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
