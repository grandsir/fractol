/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 04:58:31 by databey           #+#    #+#             */
/*   Updated: 2024/03/05 12:25:09 by databey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double mod_2(double x, double y) 
{
	return x * x + y * y;
}

int f_mandelbrot(t_global *g, double re, double im) {
    double z_re;
	double z_im;
	double temp;
	double mod;
	int iterations;

	z_re = 0;
	z_im = 0;
    iterations = 0;

    while (mod_2(z_im, z_re) <= 4 && iterations < MAX_ITER) {
        temp = z_re * z_re - z_im * z_im + re;
        z_im = ((2 * z_re * z_im + im));
        z_re = (temp) ;
        iterations++;
    }

	mod = sqrt(mod_2(z_im, z_re));
    return ((double) iterations) - log2(fmax(1.0f, log2(mod)));
}

void print_mandelbrot(t_global *g)
{
	int		x;
	int		y;
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

			m = f_mandelbrot(g, re, im);
			if (m == MAX_ITER) 
				mlx_safe_pixel_put(g->img, x, y, 0x000000);
			else 
				mlx_safe_pixel_put(g->img, x, y, palette(g, m));
		}
	}
}