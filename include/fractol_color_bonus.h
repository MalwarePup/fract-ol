/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_color_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 00:23:01 by ladloff           #+#    #+#             */
/*   Updated: 2023/06/17 15:18:27 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_COLOR_BONUS_H
# define FRACTOL_COLOR_BONUS_H

# include <stdint.h>
# include "fractol_bonus.h"

// A (multiplier)
# define A 1664525
// C (increment)
# define C 1013904223

typedef struct s_rgb_color
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
}	t_rgb_color;

/* color.c */
t_rgb_color	get_color(int iter, uint32_t color_seed);
uint32_t	pseudo_rand(uint32_t seed);

#endif /* FRACTOL_COLOR_BONUS_H */
