/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:59:37 by ladloff           #+#    #+#             */
/*   Updated: 2023/05/27 00:51:11 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "fractol.h"
#include "mlx.h"
#include "libft.h"
#include "ft_printf.h"

static t_set	is_valid_set(char *input_str, char *set_str, t_set set)
{
	if (!ft_strcmp(input_str, set_str))
		return (set);
	else if (input_str[0] == set_str[0] && input_str[1] == '\0')
		return (set);
	return (S_ERROR);
}

bool	is_valid_double(char *str)
{
	int	dot_count;
	int	is_valid_char;

	dot_count = 0;
	is_valid_char = 0;
	if (!str)
		return (false);
	while (*str)
	{
		if (!ft_isdigit(*str) && *str != '.' && *str != '-' && *str != '+')
			return (false);
		if (*str == '-' || *str == '+')
		{
			if (is_valid_char)
				return (false);
			is_valid_char = 1;
		}
		if (*str == '.')
		{
			if (++dot_count > 1)
				return (false);
		}
		str++;
	}
	return (true);
}

static t_set	parser(int argc, char *argv[], t_complex *julia_params)
{
	if (is_valid_set(argv[1], MANDELBROT, S_MANDELBROT) == S_MANDELBROT)
		return (S_MANDELBROT);
	else if (is_valid_set(argv[1], JULIA, S_JULIA) == S_JULIA)
	{
		if (argc == 2)
			return (S_JULIA);
		else if (argc == 4 && is_valid_double(argv[2])
			&& is_valid_double(argv[3]))
		{
			julia_params->real = ft_atof(argv[2]);
			julia_params->imaginary = ft_atof(argv[3]);
			return (S_JULIA);
		}
		else
		{
			ft_printf(HSTR_0 HSTR_1 HSTR_2);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		ft_printf(HSTR_0 HSTR_1 HSTR_2);
		exit(EXIT_SUCCESS);
	}
}

void	process_fractol(int argc, char *argv[])
{
	t_mlx	*mlx;

	mlx = create_mlx();
	mlx->data->set = parser(argc, argv, &mlx->data->c);
	mlx->data->max_iter = 30;
	if (!mlx->data->c.real && !mlx->data->c.imaginary
		&& mlx->data->set == S_JULIA)
	{
		mlx->data->c.real = -0.8;
		mlx->data->c.imaginary = 0.156;
	}
	mlx->data->x_min = X_MIN;
	mlx->data->x_max = X_MAX;
	mlx->data->y_min = Y_MIN;
	mlx->data->y_max = Y_MAX;
	render_fractal(mlx);
	mlx_hook(mlx->win, DESTROY_NOTIFY, STRUCTURE_NOTIFY_MASK,
		close_window_event, mlx);
	mlx_mouse_hook(mlx->win, hook_mouse_scroll, mlx);
	mlx_key_hook(mlx->win, hook_keypress, mlx);
	mlx_loop(mlx->mlx);
}

int	main(int argc, char *argv[])
{
	if (argc < 2)
	{
		ft_printf(HSTR_0 HSTR_1 HSTR_2);
		return (EXIT_SUCCESS);
	}
	process_fractol(argc, argv);
	return (EXIT_SUCCESS);
}
