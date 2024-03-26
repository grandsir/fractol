/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 08:39:02 by databey           #+#    #+#             */
/*   Updated: 2024/03/26 14:55:54 by databey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	setup_global(void *mlx, void *mlx_win, t_global *g)
{
	g->img = NULL;
	g->mlx = mlx;
	g->mlx_win = mlx_win;
	g->offset_x = 0;
	g->offset_y = 0;
	g->event.mouse_hold = 0;
	g->event.mouse_pan_x = 0;
	g->event.mouse_pan_y = 0;
	g->event.world_scale = 1.0f;
	g->palette = 1;
	g->z_re = 0.285;
	g->z_im = 0.01;
}

void	screen_to_world(t_global *g, t_point point, double *world_x,
		double *world_y)
{
	*world_x = ((double)point.x / g->event.world_scale + (g->offset_x));
	*world_y = ((double)point.y / g->event.world_scale + (g->offset_y));
}
