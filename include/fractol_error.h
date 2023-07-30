/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_error.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 14:32:56 by ladloff           #+#    #+#             */
/*   Updated: 2023/07/30 10:50:44 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_ERROR_H
# define FRACTOL_ERROR_H

# include "fractol.h"
# include "fractol_mlx.h"

# define ERR_STR_MEM_ALLOC "Error: Memory allocation failed"
# define ERR_STR_MLX_INIT "Error: Failed to initialize mlx"
# define ERR_STR_MLX_WIN "Error: Failed to create a new window"
# define ERR_STR_MLX_IMG "Error: Failed to create new image"
# define ERR_STR_MLX_DATA_ADDR "Error: Failed to get data address"

typedef enum t_fractol_errno
{
	FRACTOL_ERR_MEM_ALLOC,
	FRACTOL_ERR_MLX_INIT,
	FRACTOL_ERR_MLX_WIN,
	FRACTOL_ERR_MLX_IMG,
	FRACTOL_ERR_MLX_DATA_ADDR,
	FRACTOL_ERR_OPEN,
	FRACTOL_ERR_READ
}	t_fractol_errno;

/* fractol_error.c */
void	mlx_error_handler(t_fractol_errno fractol_errno, t_mlx *mlx);

#endif /* FRACTOL_ERROR_H */
