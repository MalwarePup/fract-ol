/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 21:10:50 by ladloff           #+#    #+#             */
/*   Updated: 2023/07/26 13:56:45 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fractol_sets.h"

void	burning_ship(t_complex c, double *iter, int max_iter)
{
	t_complex	z;
	double		temp;
	double		real_squared;
	double		imaginary_squared;

	z.real = 0.0;
	z.imaginary = 0.0;
	real_squared = 0.0;
	imaginary_squared = 0.0;
	while (real_squared + imaginary_squared <= 4 && *iter < max_iter)
	{
		temp = real_squared - imaginary_squared + c.real;
		z.imaginary = fabs(2.0 * z.real * z.imaginary) + c.imaginary;
		z.real = temp;
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
