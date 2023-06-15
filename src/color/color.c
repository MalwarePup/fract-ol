/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 00:22:48 by ladloff           #+#    #+#             */
/*   Updated: 2023/06/15 13:03:52 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fractol_color.h"

// 0xRRGGBB
uint32_t	get_color(int iter, uint32_t color_seed)
{
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;
	float		frequency;

	frequency = 0.1F;
	r = (sin(frequency * iter + 4 + sin(color_seed / 30.0)) * 127 + 128);
	g = (sin(frequency * iter + 2 + cos(color_seed / 20.0)) * 127 + 128);
	b = (sin(frequency * iter + 1 + tan(color_seed / 10.0)) * 127 + 128);
	return ((r << 16) | (g << 8) | b);
}

uint32_t	pseudo_rand(uint32_t seed)
{
	uint32_t	a;
	uint32_t	c;
	uint32_t	m;

	a = 1103515245;
	c = 12345;
	m = 1 << 31;
	return ((a * seed + c) % m);
}
