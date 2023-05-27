/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:04:38 by ladloff           #+#    #+#             */
/*   Updated: 2023/05/27 15:20:48 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initialize_data(t_mlx *mlx)
{
	mlx->data.max_iter = 30;
	if (!mlx->data.c.real && !mlx->data.c.imaginary
		&& mlx->data.set == S_JULIA)
	{
		mlx->data.c.real = -0.8;
		mlx->data.c.imaginary = 0.156;
	}
	mlx->data.x_min = X_MIN;
	mlx->data.x_max = X_MAX;
	mlx->data.y_min = Y_MIN;
	mlx->data.y_max = Y_MAX;
}
