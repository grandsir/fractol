/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 08:43:23 by databey           #+#    #+#             */
/*   Updated: 2024/03/26 13:13:31 by databey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	reinit_image(t_global *g)
{
	if (g->mlx && g->img)
		mlx_destroy_image(g->mlx, g->img);
	if (g->buf)
		g->buf = NULL;
	init_image(g);
}

int	error(const char *str)
{
	ft_printf(str);
	ft_printf("\n\e[0;37m");
	return (1);
}

void	close_window(int exit_code, t_global *g)
{
	if (!g)
		exit(exit_code);
	if (g->img)
		mlx_destroy_image(g->mlx, g->img);
	if (g->mlx_win && g->mlx)
		mlx_destroy_window(g->mlx, g->mlx_win);
	if (g->mlx)
		free(g->mlx);
	system("leaks fractol");
	exit(exit_code);
}
