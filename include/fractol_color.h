/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_color.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 00:23:01 by ladloff           #+#    #+#             */
/*   Updated: 2023/05/29 01:08:13 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_COLOR_H
# define FRACTOL_COLOR_H

# include <stdint.h>
# include "fractol.h"

/* color.c */
uint32_t	get_color(int iter, int max_iter);

#endif /* FRACTOL_COLOR_H */
