/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:25:48 by databey           #+#    #+#             */
/*   Updated: 2024/03/26 13:46:45 by databey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void clean_init(t_global *g)
{
	g->mlx = NULL;
	g->mlx_win = NULL;
}

static int	on_frame_update(t_global *g)
{
	init_image(g); 
	mlx_clear_window(g->mlx, g->mlx_win);
	print_fractal(g);
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->img, 0, 0);
	return (0);
}

static void	setup_events(t_global *g)
{
	mlx_loop_hook(g->mlx, on_frame_update, g);
	mlx_key_hook(g->mlx_win, setup_keys, g);
	setup_mouse_events(g);
}

int	main(int argc, char *argv[])
{
	void		*mlx;
	void		*mlx_win;
	t_global	g;

	clean_init(&g);
	mlx = mlx_init();
	if (mlx == NULL)
	{
		return (error("Can not initialize MLX"));
	}
	mlx_win = mlx_new_window(mlx, SCREEN_WIDTH * 2, SCREEN_HEIGHT * 2, "Fractol");
	if (mlx_win == NULL)
	{
		free(mlx);
		return (error("Can not iniitalize MLX_WINDOW"));
	}
	setup_global(mlx, mlx_win, &g);
	if (handle_arg(&g, argc, argv) == 1)
		return (1);
	setup_events(&g);
	mlx_loop(mlx);
	return (0);
}
