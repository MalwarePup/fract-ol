/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 19:30:24 by ladloff           #+#    #+#             */
/*   Updated: 2023/05/28 22:54:57 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_sets.h"

void	julia(t_complex *z, t_complex c, int *iter, int max_iter)
{
	double	temp_real;
	double	real_squared;
	double	imaginary_squared;

	real_squared = z->real * z->real;
	imaginary_squared = z->imaginary * z->imaginary;
	while (real_squared + imaginary_squared <= 4 && *iter < max_iter)
	{
		temp_real = real_squared - imaginary_squared + c.real;
		z->imaginary = 2 * z->real * z->imaginary + c.imaginary;
		z->real = temp_real;
		real_squared = z->real * z->real;
		imaginary_squared = z->imaginary * z->imaginary;
		(*iter)++;
	}
}
