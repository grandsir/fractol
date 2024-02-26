/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:25:48 by databey           #+#    #+#             */
/*   Updated: 2024/02/26 01:06:09 by databey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	on_frame_update(t_global *g)
{
	init_image(g);
	mlx_clear_window(g->mlx, g->mlx_win);

    for (int y = 0; y <= 10; y++) {
        int sx = 0, sy = y;
        int ex = 10, ey = y;
        int pixel_sx, pixel_sy, pixel_ex, pixel_ey;
        world_to_screen(g, sx, sy, &pixel_sx, &pixel_sy);
        world_to_screen(g, ex, ey, &pixel_ex, &pixel_ey);
		draw_line(g, pixel_sx, pixel_sy, pixel_ex, pixel_ey);
    }
	for (int x = 0; x <= 10; x++) {
        int sx = x, sy = 0;
        int ex = x, ey = 10;
        int pixel_sx, pixel_sy, pixel_ex, pixel_ey;
        world_to_screen(g, sx, sy, &pixel_sx, &pixel_sy);
        world_to_screen(g, ex, ey, &pixel_ex, &pixel_ey);
		draw_line(g, pixel_sx, pixel_sy, pixel_ex, pixel_ey);
    }
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->img->img, 0, 0);
	return (0);
}

void	setup_events(t_global *g)
{
	mlx_loop_hook(g->mlx, on_frame_update, g);
	setup_mouse_events(g);
}

int				main(int argc, char *argv[])
{
	void		*mlx;
	void		*mlx_win;
	t_global	g;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "Fractol");
	setup_global(mlx, mlx_win, &g);
	setup_events(&g);
	mlx_loop(mlx);
	return (0);
}
