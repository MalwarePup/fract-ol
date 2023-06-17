/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mlx_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 22:36:12 by ladloff           #+#    #+#             */
/*   Updated: 2023/06/17 15:18:16 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_MLX_BONUS_H
# define FRACTOL_MLX_BONUS_H

# include "fractol_bonus.h"

/* Default value of each set */
# define MAX_ITER 50
# define X_MIN -2.0
# define X_MAX 2.0
# define Y_MIN -2.0
# define Y_MAX 2.0

/**
 * Represents the real part of the Julia's set constant if no args is sent.
 * Modify this value to change the appearance of the set.
 */
# define JULIA_REAL -0.8

/**
 * Represents the imaginary part of the Julia's set constant if no args is sent.
 * Modify this value to change the appearance of the set.
 */
# define JULIA_IMAGINARY 0.156

/* ressources_manager */
t_mlx	setup_mlx(int argc, char *argv[]);
void	cleanup_mlx(t_mlx *mlx);
void	initialize_data(t_data *data);

#endif /* FRACTOL_MLX_BONUS_H */
