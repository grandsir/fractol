/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:25:48 by databey           #+#    #+#             */
/*   Updated: 2024/03/04 16:13:55 by databey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	on_frame_update(t_global *g)
{
	init_image(g);
	mlx_clear_window(g->mlx, g->mlx_win);
	print_mandelbrot(g);
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->img->img, 0, 0);
	return (0);
}

void	setup_events(t_global *g)
{
	mlx_loop_hook(g->mlx, on_frame_update, g);
	mlx_key_hook(g->mlx_win, setup_keys, g);
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
