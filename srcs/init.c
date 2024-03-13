/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:09:53 by databey           #+#    #+#             */
/*   Updated: 2024/03/13 16:34:38 by databey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	check_for_letters(char *str)
{
	int	i;
	int	c;

	i = 0;
	c = 1;
	while (str[i])
	{
		if (ft_isalpha(str[i]))
			c = 0;
		i++;
	}
	return (c);
}
int init_julia(t_global *g, int argc, char *argv[])
{
	char str[50];

	if (argc != 4)
		return fatal_error("Not enough parameters.\nCorrect Usage is: ./fractol 2 <real constant> <imaginary constant>");
	if (!check_for_letters(argv[2]) || !check_for_letters(argv[3]))
		return fatal_error("Parameters must be numbers.");
	g->z_re = ft_atof(argv[2]);
	g->z_im = ft_atof(argv[3]);
	return (0);
}

int handle_arg(t_global *g, int argc, char *argv[])
{
	int first;
	int second;

	if (argc == 1)
		return fatal_error("No arguments provided.\nCorrect usage is: ./fractol <Fractal number>\nAvailable fractal numbers:\nn\e[1;36m1- Mandelbrot\n2- Julia");
	if (argc >= 2)
	{
		first = ft_atoi(argv[1]);
		if (!first || first > 2 || first < 0)
			return fatal_error("Invalid fractal number\nAvailable fractal numbers:\n\e[1;36m1- Mandelbrot\n2- Julia");
		g->fractal = first;
		if (first == JULIA)
			return (init_julia(g, argc, argv));
	}
	return (0);
}

void init_image(t_global *g)
{
	t_data *img;

	clear_image_memory(g);
	img = malloc(sizeof (t_data));
	img->img = mlx_new_image(g->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
    img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,
                                &img->endian);	
	g->img = img;
}
