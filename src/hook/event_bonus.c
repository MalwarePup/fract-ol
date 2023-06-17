/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 23:38:16 by ladloff           #+#    #+#             */
/*   Updated: 2023/06/17 15:14:42 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fractol_hook_bonus.h"
#include "fractol_error_bonus.h"

int	close_window_event(t_mlx *mlx)
{
	cleanup_mlx(mlx);
	exit(EXIT_SUCCESS);
}
