/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:05:12 by ladloff           #+#    #+#             */
/*   Updated: 2023/06/14 13:56:58 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol_mlx.h"
#include "fractol_error.h"
#include "fractol_parser.h"
#include "libft.h"

t_mlx	setup_mlx(int argc, char *argv[])
{
	t_mlx	mlx;

	ft_memset(&mlx, 0, sizeof(t_mlx));
	mlx.data.set = parse_arguments(argc, argv, &mlx.data.c);
	mlx.mlx = mlx_init();
	if (!mlx.mlx)
		mlx_error_handler(FRACTOL_ERR_MLX_INIT, &mlx);
	mlx.win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, TITLE);
	if (!mlx.win)
		mlx_error_handler(FRACTOL_ERR_MLX_WIN, &mlx);
	mlx.img = mlx_new_image(mlx.mlx, WIDTH, HEIGHT);
	if (!mlx.img)
		mlx_error_handler(FRACTOL_ERR_MLX_IMG, &mlx);
	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bpp,
			&mlx.size_line, &mlx.endian);
	if (!mlx.addr)
		mlx_error_handler(FRACTOL_ERR_MLX_DATA_ADDR, &mlx);
	return (mlx);
}

void	cleanup_mlx(t_mlx *mlx)
{
	if (!mlx)
		return ;
	if (mlx->img)
		mlx_destroy_image(mlx->mlx, mlx->img);
	if (mlx->win)
		mlx_destroy_window(mlx->mlx, mlx->win);
	if (mlx->mlx)
	{
		MLX_END_LOOP(mlx);
		MLX_DESTROY_DISPLAY(mlx);
		free(mlx->mlx);
	}
}

void	initialize_data(t_data *data)
{
	data->max_iter = MAX_ITER;
	if (!data->c.real && !data->c.imaginary && data->set == S_JULIA)
	{
		data->c.real = JULIA_REAL;
		data->c.imaginary = JULIA_IMAGINARY;
	}
	data->x_min = X_MIN;
	data->x_max = X_MAX;
	data->y_min = Y_MIN;
	data->y_max = Y_MAX;
}
