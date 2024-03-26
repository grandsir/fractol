/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:43:34 by databey           #+#    #+#             */
/*   Updated: 2024/03/25 13:52:44 by databey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	mod_2(double x, double y)
{
	return (x * x + y * y);
}

int	f_julia(t_global *g, double re, double im)
{
	double	z_re;
	double	z_im;
	double	temp;
	double	mod;
	int		iterations;

	z_re = re;
	z_im = im;
	iterations = 0;
	while (mod_2(z_im, z_re) <= 4 && iterations < MAX_ITER)
	{
		temp = z_re * z_re - z_im * z_im + g->z_re;
		z_im = ((2 * z_re * z_im + g->z_im));
		z_re = (temp);
		iterations++;
	}
	mod = sqrt(mod_2(z_im, z_re));
	return (((double)iterations) - log2(fmax(1.0f, log2(mod))));
}
