/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_render_bonus.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 01:00:51 by ladloff           #+#    #+#             */
/*   Updated: 2023/06/17 15:18:57 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_RENDER_BONUS_H
# define FRACTOL_RENDER_BONUS_H

# include "fractol_bonus.h"

/* render.c */

/**
 * Maps pixel coordinates to complex number coordinates.
 *
 * This function takes the pixel coordinates (x, y) of an image and maps them
 * to corresponding complex number coordinates (real, imaginary) within a
 * specified range. The range is defined by the t_mlx structure passed as an
 * argument, which contains the minimum and maximum values for the x and y axes.
 *
 * @param c     A pointer to a t_complex structure to store the mapped complex
 *              number coordinates.
 * @param x     The x-coordinate of the pixel.
 * @param y     The y-coordinate of the pixel.
 * @param mlx   A pointer to a t_mlx structure containing the x and y axis
 *              ranges.
 */
void	map_pixel_to_complex(t_complex *c, int x, int y, t_mlx *mlx);

void	render_fractal(t_mlx *mlx);

#endif /* FRACTOL_RENDER_BONUS_H */
