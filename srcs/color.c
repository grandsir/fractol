/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:12:59 by databey           #+#    #+#             */
/*   Updated: 2024/03/14 13:59:53 by databey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	purple_palette(int m)
{
	int	r;
	int	g;
	int	b;

	r = (int)((double)160 * ((double)m / MAX_ITER));
	g = (int)((double)32 * ((double)m / MAX_ITER));
	b = (int)((double)240 * ((double)m / MAX_ITER));
	return ((r << 16) | (g << 8) | b);
}

static int	rainbow_palette(int m)
{
	int	r;
	int	g;
	int	b;

    r = (int)((double)200 * ((double)m / MAX_ITER));
    g = (int)((double)50 * ((double)m / MAX_ITER));
    b = (int)((double)250 * ((double)m / MAX_ITER));
	return (r * g * b * m);
}

static int rainbow_palette_2(int m) {
    int r;
    int g;
    int b;

    r = (int)((double)255 * ((double)m / MAX_ITER));
    g = (int)((double)255 * ((double)m / MAX_ITER));
    b = (int)((double)255 * ((double)m / MAX_ITER));

    return (r << 4) | (g << 4) | b;
}
static int	red_palette(int m)
{
	int	r;
	int	g;
	int	b;

	r = (int)((double)255 * ((double)m / MAX_ITER));
	g = 0;
	b = 0;
	return ((r << 16) | (g << 8) | b);
}

int	palette(t_global *g, int m)
{
	int f;

	f = g->palette % 4;
	if (f == 0)
		return purple_palette(m);
	if (f == 1)
		return red_palette(m);
	if (f == 2)
		return rainbow_palette(m);
	if (f == 3)
		return rainbow_palette_2(m);
	return (0);
}