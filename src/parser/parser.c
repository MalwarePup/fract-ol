/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 14:58:11 by ladloff           #+#    #+#             */
/*   Updated: 2023/05/29 01:07:49 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "fractol_parser.h"
#include "libft.h"
#include "ft_printf.h"

static t_set	is_valid_set(char *str, char *set_str, t_set set)
{
	if (!ft_strcmp(str, set_str)
		|| (str[0] == set_str[0] && str[1] == '\0'))
		return (set);
	return (S_ERROR);
}

static bool	is_valid_double(char *str)
{
	bool			valid_sign;
	unsigned char	dot_count;

	if (!str)
		return (false);
	dot_count = 0;
	valid_sign = false;
	while (*str)
	{
		if (ft_isdigit(*str) || *str == '.')
		{
			if (*str == '.' && ++dot_count > 1)
				return (false);
		}
		else if (*str == '-' || *str == '+')
		{
			if (valid_sign)
				return (false);
			valid_sign = true;
		}
		else
			return (false);
		str++;
	}
	return (true);
}

void	print_option_menu(void)
{
	ft_printf(HSTR_0 HSTR_1 HSTR_2 HSTR_3);
}

t_set	parse_arguments(int argc, char *argv[], t_complex *z)
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
			z->real = ft_atof(argv[2]);
			z->imaginary = ft_atof(argv[3]);
			return (S_JULIA);
		}
	}
	else if (is_valid_set(argv[1], BURNING_SHIP, S_BURNING_SHIP)
		== S_BURNING_SHIP)
		return (S_BURNING_SHIP);
	print_option_menu();
	exit(S_ERROR);
}
