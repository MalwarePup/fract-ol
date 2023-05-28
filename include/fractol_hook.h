/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_hook.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 23:18:25 by ladloff           #+#    #+#             */
/*   Updated: 2023/05/29 00:58:15 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_HOOK_H
# define FRACTOL_HOOK_H

# include "fractol.h"

/**
 * For Apple we swap the scroll button due to Apple idea :D
 * For Linux use X11 lib to get the key
 */
# ifdef __APPLE__
#  define SCROLL_DOWN 5
#  define SCROLL_UP 4
# elif __linux__
#  include <X11/keysym.h>
#  define SCROLL_UP 4
#  define SCROLL_DOWN 5
# endif

/**
 * Represents the zoom scaling factor when scrolling up or down with the mouse
 * Modify this value to 1.0 to cancel the zoom (1.0 * 1.0) = 1.0
 * If we scroll up once (1.0 * 1.1) = 1 and once again (1.1 * 1.1) = 1.21
 * This the same idea with scroll down, divide every time (see the code in zoom)
 */
# define ZOOM_SCALING_FACTOR 1.1

/**
 *  Represents the ration used to move when using the key.
 *  We can imagine this value like a pourcentage.
 *  Currently we move at 5% and 1 is 100%
 */
# define OFFSET_RATIO 0.05

# define DESTROY_NOTIFY 17
# define STRUCTURE_NOTIFY_MASK 1L<<17

/* event.h */
int		close_window_event(t_mlx *mlx);

/* hook_manager.c */
void	hook_manager(t_mlx *mlx);

/* keypress_xxx.c */
int		hook_keypress(int keycode, t_mlx *mlx);

/* movement.c */
void	move_left(t_mlx *mlx);
void	move_up(t_mlx *mlx);
void	move_right(t_mlx *mlx);
void	move_down(t_mlx *mlx);

/* scroll.c */
void	zoom(t_mlx *mlx, int button, t_complex mouse);
int		hook_mouse_scroll(int button, int x, int y, t_mlx *mlx);

#endif /* FRACTOL_HOOK_H */
