/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 11:58:41 by databey           #+#    #+#             */
/*   Updated: 2024/03/14 16:52:38 by databey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int on_mouse_down(int button, int x, int y, t_global *g)
{
	double mouse_x;
	double mouse_y;
	double mouse_x_scaled;
	double mouse_y_scaled;
	if (!g->event.mouse_hold && button == 1)
	{
		g->event.mouse_pan_x = x;
		g->event.mouse_pan_y = y;
		g->event.mouse_hold = 1;
	}
	screen_to_world(g, x, y, &mouse_x, &mouse_y);
	if (button == 4)
		g->event.world_scale *= 1.05f;
	if (button == 5)
		g->event.world_scale *= 0.95f;
	screen_to_world(g, x, y, &mouse_x_scaled, &mouse_y_scaled);
	g->offset_x += (double)(mouse_x - mouse_x_scaled);
	g->offset_y += (double)(mouse_y - mouse_y_scaled);
	return (1);
}

int on_mouse_up(int button, int x, int y, t_global *g)
{
	g->event.mouse_hold = 0;
	g->event.mouse_pan_x = 0;	
	g->event.mouse_pan_y = 0;

	return (1);
}

int on_mouse_move(int x, int y, t_global *g)
{
	g->event.mouse_x = x;
	g->event.mouse_y = y;
	if (g->event.mouse_hold)
	{
		g->offset_x -= (x - g->event.mouse_pan_x) / g->event.world_scale;
		g->offset_y -= (y - g->event.mouse_pan_y) / g->event.world_scale;
		g->event.mouse_pan_x = x;
		g->event.mouse_pan_y = y;
	}

	return (1);
}

int setup_mouse_events(t_global *g)
{
	mlx_hook(g->mlx_win, 4, 0L, on_mouse_down, g);
	mlx_hook(g->mlx_win, 5, 0L, on_mouse_up, g);
	mlx_hook(g->mlx_win, 6, 0L, on_mouse_move, g);

	return (1);
}