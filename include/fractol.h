/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:59:39 by ladloff           #+#    #+#             */
/*   Updated: 2023/07/26 13:34:03 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdint.h>

# define WIDTH 800
# define HEIGHT 800
# define TITLE "Fractal Viewer"

typedef enum s_set
{
	S_JULIA,
	S_MANDELBROT,
	S_BURNING_SHIP,
	S_ERROR
}	t_set;

typedef struct s_complex
{
	double	real;
	double	imaginary;
}	t_complex;

typedef struct s_data
{
	t_complex	c;
	t_complex	z;
	int			max_iter;
	double		iter;
	t_set		set;
	double		x_min;
	double		x_max;
	double		y_min;
	double		y_max;
	uint32_t	color_shift;
}	t_data;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
	t_data	data;
}	t_mlx;

#endif /* FRACTOL_H */
