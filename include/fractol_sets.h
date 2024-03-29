/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_sets.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 21:54:55 by ladloff           #+#    #+#             */
/*   Updated: 2023/07/26 13:56:27 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_SETS_H
# define FRACTOL_SETS_H

# include "fractol.h"

/* mandelbrot.c */
void	mandelbrot(t_complex c, double *iter, int max_iter);

/* julia.c */
void	julia(t_complex *z, t_complex c, double *iter, int max_iter);

/* burning_ship.c */
void	burning_ship(t_complex c, double *iter, int max_iter);

#endif /* FRACTOL_SETS_H */
