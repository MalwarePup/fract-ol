/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 19:30:24 by ladloff           #+#    #+#             */
/*   Updated: 2023/05/26 23:29:23 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(t_complex *z, t_complex c, uint32_t *iter, uint32_t max_iter)
{
	double	temp;

	while ((z->real * z->real + z->imaginary * z->imaginary < 4)
		&& (*iter < max_iter))
	{
		temp = z->real * z->real - z->imaginary * z->imaginary + c.real;
		z->imaginary = 2 * z->real * z->imaginary + c.imaginary;
		z->real = temp;
		(*iter)++;
	}
}
