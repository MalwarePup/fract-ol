/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 23:21:53 by ladloff           #+#    #+#             */
/*   Updated: 2023/05/29 01:04:43 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_hook.h"
#include "fractol_render.h"

void	move_left(t_mlx *mlx)
{
	double	offset;

	offset = (mlx->data.x_max - mlx->data.x_min) * OFFSET_RATIO;
	mlx->data.x_min -= offset;
	mlx->data.x_max -= offset;
	render_fractal(mlx);
}

void	move_up(t_mlx *mlx)
{
	double	offset;

	offset = (mlx->data.y_max - mlx->data.y_min) * OFFSET_RATIO;
	mlx->data.y_min -= offset;
	mlx->data.y_max -= offset;
	render_fractal(mlx);
}

void	move_right(t_mlx *mlx)
{
	double	offset;

	offset = (mlx->data.x_max - mlx->data.x_min) * OFFSET_RATIO;
	mlx->data.x_min += offset;
	mlx->data.x_max += offset;
	render_fractal(mlx);
}

void	move_down(t_mlx *mlx)
{
	double	offset;

	offset = (mlx->data.y_max - mlx->data.y_min) * OFFSET_RATIO;
	mlx->data.y_min += offset;
	mlx->data.y_max += offset;
	render_fractal(mlx);
}
