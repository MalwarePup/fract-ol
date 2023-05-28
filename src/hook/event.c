/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 23:38:16 by ladloff           #+#    #+#             */
/*   Updated: 2023/05/29 01:09:13 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fractol_hook.h"
#include "fractol_error.h"

int	close_window_event(t_mlx *mlx)
{
	cleanup_mlx(mlx);
	exit(EXIT_SUCCESS);
}
