/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:09:53 by databey           #+#    #+#             */
/*   Updated: 2024/03/26 13:47:20 by databey          ###   ########.fr       */
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

int	init_julia(t_global *g, int argc, char *argv[])
{
	char	str[50];

	if (argc != 4)
	{
		error("Not enough parameters, Correct Usage is:");
		return (error("./fractol 2 <real constant> <imaginary constant>"));
	}
	if (!check_for_letters(argv[2]) || !check_for_letters(argv[3]))
		return (error("Parameters must be numbers."));
	g->z_re = ft_atof(argv[2]);
	g->z_im = ft_atof(argv[3]);
	return (0);
}

int	handle_arg(t_global *g, int argc, char *argv[])
{
	int	first;
	int	second;

	if (argc == 1)
	{
		error("No arguments provided");
		error("Correct usage is: ./fractol <Fractal number>");
		return (error("\e[1);36m1- Mandelbrot\n2- Julia\n3- Burning Ship"));
	}
	if (argc >= 2)
	{
		first = ft_atoi(argv[1]);
		if (!first || first > 3 || first < 0)
		{
			error("Invalid fractal number\nAvailable fractal numbers:");
			return (error("\e[1);36m1- Mandelbrot\n2- Julia\n3- Burning Ship"));
		}
		g->fractal = first;
		if (first == JULIA)
			return (init_julia(g, argc, argv));
	}
	return (0);
}

void	init_image(t_global *g)
{
	g->img = mlx_new_image(g->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!g->img)
	{
		error("image creation error");
		close_window(1, g);
	}
	g->img->addr = mlx_get_data_addr(g->img, &g->img->bits_per_pixel,
			&g->img->line_length, &g->img->endian);
}
