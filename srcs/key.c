/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:08:18 by databey           #+#    #+#             */
/*   Updated: 2024/03/07 16:15:15 by databey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void move(t_global *g, int x, int y)
{
	g->offset_x += x / g->event.world_scale;
	g->offset_y += y / g->event.world_scale;
}

void scale(t_global *g, int x, int y, double scale)
{
	int mx;
	int my;
	int smx;
	int smy;
	screen_to_world(g, x, y, &mx, &my);
	g->event.world_scale *= scale;
	screen_to_world(g, x, y, &smx, &smy);
	g->offset_x += (mx - smx);
	g->offset_y += (my - smy);
}

int	setup_keys(int keycode, t_global *g)
{
	if (keycode == KEY_SPACE)
		scale(g, g->event.mouse_x, g->event.mouse_y, 1.5f);
	else if (keycode == KEY_BACKSPACE)
		scale(g, g->event.mouse_x, g->event.mouse_y, 0.5f);
	else if ((keycode == KEY_UP) || (keycode == KEY_W))
		move(g, 0, (-1) * (SCREEN_HEIGHT / 10));
	else if ((keycode == KEY_LEFT) || (keycode == KEY_A))
		move(g, (-1) * (SCREEN_WIDTH / 10), 0);
	else if ((keycode == KEY_DOWN) || (keycode == KEY_S))
		move(g, 0, (SCREEN_HEIGHT / 10));
	else if ((keycode == KEY_RIGHT) || (keycode == KEY_D))
		move(g, (SCREEN_WIDTH / 10), 0);
	else if (keycode == KEY_P)
		g->palette += 1;
	else if (keycode == KEY_C)
		g->fractal += 1;
	else if (keycode == KEY_ESCAPE)
		close_window(g);
	else
		return (0);
	return (1);
}
