/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 23:21:53 by ladloff           #+#    #+#             */
/*   Updated: 2023/06/17 15:15:39 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_hook_bonus.h"
#include "fractol_render_bonus.h"

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
