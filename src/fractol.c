/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:59:37 by ladloff           #+#    #+#             */
/*   Updated: 2023/05/29 01:08:59 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "fractol.h"
#include "fractol_mlx.h"
#include "fractol_hook.h"
#include "fractol_parser.h"

int	main(int argc, char *argv[])
{
	t_mlx	mlx;

	if (argc < 2)
	{
		print_option_menu();
		return (EXIT_SUCCESS);
	}
	mlx = setup_mlx();
	mlx.data.set = parse_arguments(argc, argv, &mlx.data.c);
	initialize_data(&mlx.data);
	hook_manager(&mlx);
	mlx_loop(mlx.mlx);
	return (EXIT_SUCCESS);
}
