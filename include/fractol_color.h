/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_color.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 00:23:01 by ladloff           #+#    #+#             */
/*   Updated: 2023/06/15 13:52:46 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_COLOR_H
# define FRACTOL_COLOR_H

# include <stdint.h>
# include "fractol.h"

// A (multiplier)
# define A 1664525
// C (increment)
# define C 1013904223

/* color.c */
uint32_t	get_color(int iter, uint32_t color_seed);
uint32_t	pseudo_rand(uint32_t seed);

#endif /* FRACTOL_COLOR_H */
