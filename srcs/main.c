/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:25:48 by databey           #+#    #+#             */
/*   Updated: 2024/03/07 16:15:12 by databey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	on_frame_update(t_global *g)
{
	init_image(g);
	mlx_clear_window(g->mlx, g->mlx_win);
	print_fractal(g);
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->img->img, 0, 0);
	return (0);
}

static void	setup_events(t_global *g)
{
	mlx_loop_hook(g->mlx, on_frame_update, g);
	mlx_key_hook(g->mlx_win, setup_keys, g);
	setup_mouse_events(g);
}

int handle_arg(t_global *g, int argc, char *argv[])
{
	int first;
	int second;

	if (argc == 1)
		return fatal_error("No arguments provided.\nCorrect usage is: ./fractol <Fractal number> <Julia Complex>\nAvailable fractal numbers:\n1- Mandelbrot\n2- Julia");
	if (argc >= 2)
	{
		first = ft_atoi(argv[1]);
		if (!first || first > 2)
			return fatal_error("Invalid fractal number\nAvailable fractal numbers:\n1- Mandelbrot\n2- Julia");
		g->fractal = first;
	}
	return (0);
}

int fatal_error(const char *reason)
{
	ft_printf("Fatal Error: ");
	ft_printf(reason);
	ft_printf("\n");
	return (1);
}

int				main(int argc, char *argv[])
{
	void		*mlx;
	void		*mlx_win;
	t_global	g;

	mlx = mlx_init();
	if (mlx == NULL)
		return fatal_error("Can not initialize MLX");
	mlx_win = mlx_new_window(mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "Fractol");
	if (mlx_win == NULL)
	{
		free(mlx);
		return fatal_error("Can not iniitalize MLX_WINDOW");
	}
	setup_global(mlx, mlx_win, &g);
	if (handle_arg(&g, argc, argv) == 1)
		return (1);
	setup_events(&g);
	mlx_loop(mlx);
	return (0);
}
