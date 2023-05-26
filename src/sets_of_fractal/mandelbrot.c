/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:55:45 by ladloff           #+#    #+#             */
/*   Updated: 2023/05/26 23:29:38 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_complex c, uint32_t *iter, uint32_t max_iter)
{
	t_complex	z;
	double		temp;

	z.real = 0;
	z.imaginary = 0;
	while ((z.real * z.real + z.imaginary * z.imaginary < 4)
		&& (*iter < max_iter))
	{
		temp = z.real * z.real - z.imaginary * z.imaginary + c.real;
		z.imaginary = 2 * z.real * z.imaginary + c.imaginary;
		z.real = temp;
		(*iter)++;
	}
}
