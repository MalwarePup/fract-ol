/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_manager_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 23:22:04 by ladloff           #+#    #+#             */
/*   Updated: 2023/06/17 15:14:52 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol_hook_bonus.h"
#include "fractol_render_bonus.h"

void	hook_manager(t_mlx *mlx)
{
	render_fractal(mlx);
	mlx_hook(mlx->win, DESTROY_NOTIFY, (1L << 17), close_window_event, mlx);
	mlx_mouse_hook(mlx->win, hook_mouse_scroll, mlx);
	mlx_key_hook(mlx->win, hook_keypress, mlx);
}
