/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_macos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:43:20 by ladloff           #+#    #+#             */
/*   Updated: 2023/06/17 15:34:59 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef __APPLE__

# include <stdlib.h>
# include "fractol_hook.h"
# include "fractol_mlx.h"
# include "fractol_render.h"
# include "fractol_color.h"

typedef enum e_apple_key
{
	APPLE_KEY_R = 15,
	APPLE_KEY_RIGHT_BRACKET = 30,
	APPLE_KEY_LEFT_BRACKET = 33,
	APPLE_KEY_ESCAPE = 53,
}	t_apple_key;

int	hook_keypress(int key, t_mlx *mlx)
{
	if (key == APPLE_KEY_ESCAPE)
	{
		cleanup_mlx(mlx);
		exit(EXIT_SUCCESS);
	}
	else if (key == APPLE_KEY_R)
	{
		initialize_data(&mlx->data);
		render_fractal(mlx);
	}
	if (key == APPLE_KEY_RIGHT_BRACKET)
	{
		mlx->data.max_iter++;
		render_fractal(mlx);
	}
	else if (key == APPLE_KEY_LEFT_BRACKET)
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
