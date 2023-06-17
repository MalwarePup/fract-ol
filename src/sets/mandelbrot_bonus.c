/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:55:45 by ladloff           #+#    #+#             */
/*   Updated: 2023/06/17 15:17:10 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_sets_bonus.h"

void	mandelbrot(t_complex c, int *iter, int max_iter)
{
	t_complex	z;
	double		real_squared;
	double		imaginary_squared;

	z.real = 0.0;
	z.imaginary = 0.0;
	real_squared = 0.0;
	imaginary_squared = 0.0;
	while (real_squared + imaginary_squared <= 4 && *iter < max_iter)
	{
		z.imaginary = 2.0 * z.real * z.imaginary + c.imaginary;
		z.real = real_squared - imaginary_squared + c.real;
		real_squared = z.real * z.real;
		imaginary_squared = z.imaginary * z.imaginary;
		(*iter)++;
	}
}
