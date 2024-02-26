/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 08:39:02 by databey           #+#    #+#             */
/*   Updated: 2024/02/26 04:42:49 by databey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void setup_global(void *mlx, void *mlx_win, t_global *g)
{
	g->img = NULL;
	g->mlx = mlx;
	g->mlx_win = mlx_win;
	g->offset_x = -SCREEN_WIDTH / 2;
	g->offset_y = -SCREEN_HEIGHT / 2;
	g->event.mouse_hold = 0;
	g->event.mouse_pan_x = 0;
	g->event.mouse_pan_y = 0;
	g->event.world_scale = 1.0f;
	init_image(g);
}

void init_image(t_global *g)
{
	t_data *img;

	if (g->img == NULL)
		free(g->img);
	img = malloc(sizeof (t_data));
	img->img = mlx_new_image(g->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
    img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,
                                 &img->endian);	
	g->img = img;
}

void world_to_screen(t_global *g, int world_x, int world_y, int *screen_x, int *screen_y)
{
	*screen_x = (world_x - (g->offset_x)) * g->event.world_scale;
	*screen_y = (world_y - (g->offset_y)) * g->event.world_scale;
}

void screen_to_world(t_global *g, int screen_x, int screen_y, int *world_x, int *world_y)
{
	*world_x = (screen_x / g->event.world_scale + (g->offset_x));
	*world_y = (screen_y / g->event.world_scale + (g->offset_y));
}

