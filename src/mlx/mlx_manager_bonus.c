/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_manager_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:05:12 by ladloff           #+#    #+#             */
/*   Updated: 2023/06/17 15:16:01 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol_mlx_bonus.h"
#include "fractol_error_bonus.h"
#include "fractol_parser_bonus.h"
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

#ifdef __linux__

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
		mlx_loop_end(mlx->mlx);
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
	}
}

#elif __APPLE__

/**
 * Avoid the usage of mlx_loop_end and mlx_destroy_display
 * Because we use the OpenGL Lib and these functions aren't present
 */
void	cleanup_mlx(t_mlx *mlx)
{
	if (!mlx)
		return ;
	if (mlx->img)
		mlx_destroy_image(mlx->mlx, mlx->img);
	if (mlx->win)
		mlx_destroy_window(mlx->mlx, mlx->win);
	if (mlx->mlx)
		free(mlx->mlx);
}

#endif

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
