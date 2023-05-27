/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:05:12 by ladloff           #+#    #+#             */
/*   Updated: 2023/05/27 15:20:33 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include "libft.h"
#include "ft_printf.h"

void	mlx_error_handler(t_fractol_errno fractol_errno, t_mlx *mlx)
{
	if (fractol_errno == FRACTOL_ERR_MEM_ALLOC)
		ft_putendl_fd(ERR_STR_MEM_ALLOC, STDERR_FILENO);
	else if (fractol_errno == FRACTOL_ERR_MLX_INIT)
		ft_putendl_fd(ERR_STR_MLX_INIT, STDERR_FILENO);
	else if (fractol_errno == FRACTOL_ERR_MLX_WIN)
		ft_putendl_fd(ERR_STR_MLX_WIN, STDERR_FILENO);
	else if (fractol_errno == FRACTOL_ERR_MLX_IMG)
		ft_putendl_fd(ERR_STR_MLX_IMG, STDERR_FILENO);
	else if (fractol_errno == FRACTOL_ERR_MLX_DATA_ADDR)
		ft_putendl_fd(ERR_STR_MLX_DATA_ADDR, STDERR_FILENO);
	destroy_mlx(mlx);
	exit (EXIT_FAILURE);
}

t_mlx	create_mlx(void)
{
	t_mlx	mlx;

	ft_memset(&mlx.data, 0, sizeof(t_data));
	ft_memset(&mlx, 0, sizeof(t_mlx));
	mlx.mlx = mlx_init();
	if (!mlx.mlx)
		mlx_error_handler(FRACTOL_ERR_MLX_INIT, &mlx);
	mlx.win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, TITLE);
	if (!mlx.win)
		mlx_error_handler(FRACTOL_ERR_MLX_WIN, &mlx);
	mlx.img = mlx_new_image(mlx.mlx, WIDTH, HEIGHT);
	if (!mlx.img)
		mlx_error_handler(FRACTOL_ERR_MLX_IMG, &mlx);
	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bits_per_pixel,
			&mlx.size_line, &mlx.endian);
	if (!mlx.addr)
		mlx_error_handler(FRACTOL_ERR_MLX_DATA_ADDR, &mlx);
	return (mlx);
}

void	destroy_mlx(t_mlx *mlx)
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
