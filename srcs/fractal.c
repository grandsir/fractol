/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:15:20 by databey           #+#    #+#             */
/*   Updated: 2024/03/07 16:47:36 by databey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	calculate_fractal(t_global *g, double re, double im)
{
	int	iter;

	if (g->fractal == MANDELBROT)
		iter = f_mandelbrot(re, im);
	else if (g->fractal == JULIA)
		return (0);
		// nb_iter = julia(g, pr, pi);
	return (iter);
}


void print_fractal(t_global *g)
{
	double		x;
	double		y;
	double	re;
	double	im;
	int		m;
	
	x = -1;
	while(++x < SCREEN_WIDTH)
	{
		y = -1;
		while(++y < SCREEN_HEIGHT)
		{
			re = RE_START + (((x / g->event.world_scale) + g->offset_x) / SCREEN_WIDTH) * (RE_END - RE_START);
			im = IM_START + (((y / g->event.world_scale) + g->offset_y) / SCREEN_HEIGHT) * (IM_END - IM_START);

			m = calculate_fractal(g, re, im);
			if (m == MAX_ITER) 
				mlx_safe_pixel_put(g->img, x, y, 0x000000);
			else 
				mlx_safe_pixel_put(g->img, x, y, palette(g, m));
		}
	}
}