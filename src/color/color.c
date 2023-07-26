/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 00:22:48 by ladloff           #+#    #+#             */
/*   Updated: 2023/07/26 13:07:46 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>
#include "fractol_color.h"

t_rgb_color	get_color(int iter, uint32_t color_shift)
{
	t_rgb_color	color;
	float		freq;

	freq = 0.1F;
	color.r = (sin(freq * iter + 3 + sin(color_shift / 30.0)) * 127 + 128);
	color.g = (sin(freq * iter + 2 + cos(color_shift / 20.0)) * 127 + 128);
	color.b = (sin(freq * iter + 1 + tan(color_shift / 10.0)) * 127 + 128);
	return (color);
}

uint32_t	get_secure_random_uint32(void)
{
	int			random_data;
	ssize_t		bytes_read;
	uint32_t	random_value;

	random_data = open("/dev/urandom", O_RDONLY);
	if (random_data == -1)
	{
		perror("Failed to open /dev/urandom");
		exit(EXIT_FAILURE);
	}
	bytes_read = read(random_data, &random_value, sizeof(uint32_t));
	close(random_data);
	if (bytes_read != sizeof(uint32_t))
	{
		perror("Error reading random data");
		exit(EXIT_FAILURE);
	}
	return (random_value);
}
