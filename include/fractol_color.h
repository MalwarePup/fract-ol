/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_color.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 00:23:01 by ladloff           #+#    #+#             */
/*   Updated: 2023/07/26 13:06:01 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_COLOR_H
# define FRACTOL_COLOR_H

# include <stdint.h>
# include "fractol.h"

typedef struct s_rgb_color
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
}	t_rgb_color;

/* color.c */
t_rgb_color	get_color(int iter, uint32_t color_shift);
uint32_t	get_secure_random_uint32(void);

#endif /* FRACTOL_COLOR_H */
