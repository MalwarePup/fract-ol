/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mlx.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 22:36:12 by ladloff           #+#    #+#             */
/*   Updated: 2023/05/28 23:28:52 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_MLX_H
# define FRACTOL_MLX_H

# include "fractol.h"

/**
 * Avoid the usage of mlx_loop_end and mlx_destroy_display
 * Because we use the OpenGL Lib and there is no MLX function for macOS
 */
# ifdef __APPLE__
#  define MLX_END_LOOP(mlx) NULL
#  define MLX_DESTROY_DISPLAY(mlx) NULL
# elif __linux__
#  define MLX_END_LOOP(mlx) mlx_loop_end(mlx->mlx)
#  define MLX_DESTROY_DISPLAY(mlx) mlx_destroy_display(mlx->mlx)
# endif

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
t_mlx	setup_mlx(void);
void	cleanup_mlx(t_mlx *mlx);
void	initialize_data(t_data *data);

#endif /* FRACTOL_MLX_H */
