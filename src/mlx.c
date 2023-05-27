/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:05:12 by ladloff           #+#    #+#             */
/*   Updated: 2023/05/27 11:50:39 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include "libft.h"
#include "ft_printf.h"

t_mlx	*create_mlx(void)
{
	t_mlx	*new_mlx;

	new_mlx = ft_calloc(1, sizeof(t_mlx));
	if (!new_mlx)
		exit(2);
	new_mlx->mlx = mlx_init();
	if (!new_mlx->mlx)
		exit(3);
	new_mlx->win = mlx_new_window(new_mlx->mlx, WIDTH, HEIGHT, TITLE);
	if (!new_mlx->win)
		exit(3);
	new_mlx->img = mlx_new_image(new_mlx->mlx, WIDTH, HEIGHT);
	if (!new_mlx->img)
		exit(3);
	new_mlx->addr = mlx_get_data_addr(new_mlx->img, &new_mlx->bits_per_pixel,
			&new_mlx->size_line, &new_mlx->endian);
	if (!new_mlx->addr)
		exit(3);
	new_mlx->data = ft_calloc(1, sizeof(t_data));
	if (!new_mlx->data)
		exit(2);
	return (new_mlx);
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
		// mlx_loop_end(mlx->mlx);
		// mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
	}
	free(mlx->data);
	free(mlx);
}
