/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_linux.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:43:20 by ladloff           #+#    #+#             */
/*   Updated: 2023/06/17 15:33:16 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef __linux__

# include <stdlib.h>
# include "fractol_hook.h"
# include "fractol_mlx.h"
# include "fractol_render.h"
# include "fractol_color.h"

int	hook_keypress(int key, t_mlx *mlx)
{
	if (key == XK_Escape)
	{
		cleanup_mlx(mlx);
		exit(EXIT_SUCCESS);
	}
	else if (key == XK_R || key == XK_r)
	{
		initialize_data(&mlx->data);
		render_fractal(mlx);
	}
	else if (key == XK_bracketright)
	{
		mlx->data.max_iter++;
		render_fractal(mlx);
	}
	else if (key == XK_bracketleft)
	{
		if (mlx->data.max_iter > 1)
		{
			mlx->data.max_iter--;
			render_fractal(mlx);
		}
	}
	return (EXIT_SUCCESS);
}

#endif
