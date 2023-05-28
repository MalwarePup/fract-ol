/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_render.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 01:00:51 by ladloff           #+#    #+#             */
/*   Updated: 2023/05/29 01:06:15 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_RENDER_H
# define FRACTOL_RENDER_H

# include "fractol.h"

/* render.c */
void	map_pixel_to_complex(t_complex *c, int x, int y, t_mlx *mlx);
void	render_fractal(t_mlx *mlx);

#endif /* FRACTOL_RENDER_H */
