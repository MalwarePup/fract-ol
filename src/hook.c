/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:43:20 by ladloff           #+#    #+#             */
/*   Updated: 2023/05/27 21:11:04 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window_event(t_mlx *mlx)
{
	destroy_mlx(mlx);
	exit(EXIT_SUCCESS);
}

void	zoom(t_mlx *mlx, int button, t_complex mouse)
{
	double	zoom_factor;

	zoom_factor = 0.0;
	if (button == SCROLL_UP)
		zoom_factor = SCROLL_SENSITIVITY;
	else if (button == SCROLL_DOWN)
		zoom_factor = 1 / SCROLL_SENSITIVITY;
	mlx->data.x_min = mouse.real
		+ (mlx->data.x_min - mouse.real) * zoom_factor;
	mlx->data.y_min = mouse.imaginary
		+ (mlx->data.y_min - mouse.imaginary) * zoom_factor;
	mlx->data.x_max = mouse.real
		+ (mlx->data.x_max - mouse.real) * zoom_factor;
	mlx->data.y_max = mouse.imaginary
		+ (mlx->data.y_max - mouse.imaginary) * zoom_factor;
	render_fractal(mlx);
}

void	move_left(t_mlx *mlx)
{
	double offset;

	offset = (mlx->data.x_max - mlx->data.x_min) * 0.05;
	mlx->data.x_min -= offset;
	mlx->data.x_max -= offset;
	render_fractal(mlx);
}

void	move_right(t_mlx *mlx)
{
	double	offset;

	offset = (mlx->data.x_max - mlx->data.x_min) * 0.05;
	mlx->data.x_min += offset;
	mlx->data.x_max += offset;
	render_fractal(mlx);
}

void	move_up(t_mlx *mlx)
{
	double	offset;

	offset = (mlx->data.y_max - mlx->data.y_min) * 0.05;
	mlx->data.y_min -= offset;
	mlx->data.y_max -= offset;
	render_fractal(mlx);
}

void	move_down(t_mlx *mlx)
{
	double	offset;

	offset = (mlx->data.y_max - mlx->data.y_min) * 0.05;
	mlx->data.y_min += offset;
	mlx->data.y_max += offset;
	render_fractal(mlx);
}

#ifdef __linux__

int	hook_keypress(int keycode, t_mlx *mlx)
{
	if (keycode == XK_Escape)
	{
		destroy_mlx(mlx);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == XK_bracketright)
	{
		mlx->data.max_iter++;
		render_fractal(mlx);
	}
	else if (keycode == XK_bracketleft)
	{
		if (mlx->data.max_iter > 1)
		{
			mlx->data.max_iter--;
			render_fractal(mlx);
		}
	}
	else if (keycode == XK_q || keycode == XK_Q)
	{
		zoom(mlx, SCROLL_UP, mlx->data.c);
		render_fractal(mlx);
	}
	else if (keycode == XK_e || keycode == XK_e)
	{
		zoom(mlx, SCROLL_DOWN, mlx->data.c);
		render_fractal(mlx);
	}
	else if (keycode == XK_w || keycode == XK_W || keycode == XK_Up)
		move_up(mlx);
	else if (keycode == XK_a || keycode == XK_A || keycode == XK_Left)
		move_left(mlx);
	else if (keycode == XK_s || keycode == XK_S || keycode == XK_Down)
		move_down(mlx);
	else if (keycode == XK_d || keycode == XK_D || keycode == XK_Right)
		move_right(mlx);
	return (EXIT_SUCCESS);
}

#endif

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
