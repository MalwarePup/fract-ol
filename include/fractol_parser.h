/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_parser.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 22:20:09 by ladloff           #+#    #+#             */
/*   Updated: 2023/06/14 13:40:32 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_PARSER_H
# define FRACTOL_PARSER_H

# include "fractol.h"

# define HSTR_0 "Usage: fractol [OPTIONS]\n\nOptions:\n"
# define HSTR_1 "  m, mandelbrot\t\tDisplay the mandelbrot set\n"
# define HSTR_2 "  j, julia\t\tDisplay the julia set\n"
# define HSTR_3 "  b, burning_ship\tDisplaty the burning ship set\n"

# define JULIA "julia"
# define MANDELBROT "mandelbrot"
# define BURNING_SHIP "burning_ship"

/* parser.c */
void	print_option_menu(void);
t_set	parse_arguments(int argc, char *argv[], t_complex *z);

#endif /* FRACTOL_PARSER_H */
