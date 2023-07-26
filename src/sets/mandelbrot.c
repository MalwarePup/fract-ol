/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:55:45 by ladloff           #+#    #+#             */
/*   Updated: 2023/07/26 13:56:32 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fractol_sets.h"

void	mandelbrot(t_complex c, double *iter, int max_iter)
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
	if (*iter < max_iter)
	{
		*iter = *iter - log(log(sqrt(real_squared + imaginary_squared)))
			/ log(2.0);
	}
}
