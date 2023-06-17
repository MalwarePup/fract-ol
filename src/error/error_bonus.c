/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 14:32:11 by ladloff           #+#    #+#             */
/*   Updated: 2023/06/17 15:14:32 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "fractol_error_bonus.h"
#include "libft.h"

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
	cleanup_mlx(mlx);
	exit (EXIT_FAILURE);
}
