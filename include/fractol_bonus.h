/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:59:39 by ladloff           #+#    #+#             */
/*   Updated: 2023/06/17 15:11:59 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

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
	int			iter;
	t_set		set;
	double		x_min;
	double		x_max;
	double		y_min;
	double		y_max;
	uint32_t	color_seed;
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

#endif /* FRACTOL_BONUS_H */
