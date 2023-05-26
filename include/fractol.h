/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:59:39 by ladloff           #+#    #+#             */
/*   Updated: 2023/05/27 01:47:50 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdint.h>

# define HSTR_0 "Usage: fractol [OPTIONS]\n\nOptions:\n"
# define HSTR_1 "  m, mandelbrot\t\tDisplay the mandelbrot set fractal\n"
# define HSTR_2 "  j, julia\t\tDisplay the julia set fractal\n"

# define WIDTH 800
# define HEIGHT 800
# define TITLE "Fractal Viewer"

# ifdef __APPLE__
#  define K_ESC 53
#  define K_BRACKET_LEFT 33
#  define K_BRACKET_RIGHT 30
# else
#  define K_ESC 65307
#  define K_BRACKET_LEFT 91
#  define K_BRACKET_RIGHT 93
# endif

# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define SCROLL_SENSITIVITY 1.1

# define X_MIN -2.0
# define X_MAX 1.0
# define Y_MIN -1.5
# define Y_MAX 1.5

# define DESTROY_NOTIFY 17
# define STRUCTURE_NOTIFY_MASK 1L<<17

# define MANDELBROT "mandelbrot"
# define JULIA "julia"

typedef enum s_set
{
	S_MANDELBROT,
	S_JULIA,
	S_ERROR
}	t_set;

/**
 * @struct t_complex
 * @brief Struct representing a complex number.
 *
 * @param real		The real component of the complex number.
 * @param imaginary	The imaginary component of the complex number.
 */
typedef struct s_complex
{
	double	real;
	double	imaginary;
}	t_complex;

typedef struct s_data
{
	t_complex	c;
	t_complex	z;
	uint32_t	max_iter;
	uint32_t	iter;
	t_set		set;
	double		x_min;
	double		x_max;
	double		y_min;
	double		y_max;
}	t_data;

/**
 * @struct t_mlx
 * @brief Struct representing the data required for MLX graphics.
 *
 * @param mlx				The MLX context.
 * @param win				The MLX window.
 * @param img				The MLX image.
 * @param addr				The address of the image data.
 * @param bits_per_pixel	The number of bits per pixel.
 * @param size_line			The size of a line in bytes.
 * @param endian			The endian value.
 */
typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	t_data	*data;
}	t_mlx;

t_mlx	*create_mlx(void);
void	destroy_mlx(t_mlx *mlx);

int		close_window_event(t_mlx *mlx);
int		hook_keypress(int keycode, t_mlx *mlx);
int		hook_mouse_scroll(int button, int x, int y, t_mlx *mlx);

void	mandelbrot(t_complex c, uint32_t *iter, uint32_t max_iter);

void	julia(t_complex *z, t_complex c, uint32_t *iter, uint32_t max_iter);

void	map_pixel_to_complex(t_complex *c, int32_t x, int32_t y, t_mlx *mlx);
void	render_fractal(t_mlx *mlx);

#endif /* FRACTOL_H */
