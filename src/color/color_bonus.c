/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 00:22:48 by ladloff           #+#    #+#             */
/*   Updated: 2023/06/17 15:14:22 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fractol_color_bonus.h"

t_rgb_color	get_color(int iter, uint32_t color_seed)
{
	t_rgb_color	color;
	float		frequency;

	frequency = 0.1F;
	color.r = (sin(frequency * iter + 20 + sin(color_seed / 30.0)) * 127 + 128);
	color.g = (sin(frequency * iter + 2 + cos(color_seed / 20.0)) * 127 + 128);
	color.b = (sin(frequency * iter + 1 + tan(color_seed / 10.0)) * 127 + 128);
	return (color);
}

/**
 * A pseudo random number generator using the Linear congruential generator
 * algorithm
 */
uint32_t	pseudo_rand(uint32_t seed)
{
	return (A * seed + C);
}
