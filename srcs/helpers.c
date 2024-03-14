/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 08:43:23 by databey           #+#    #+#             */
/*   Updated: 2024/03/14 16:57:33 by databey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void clear_image_memory(t_global *g)
{
    if (g->img)
    {
        free(g->img);
        if (g->img->addr)
            free(g->img->addr);
    }
}

int fatal_error(const char *str) {
    ft_printf("\e[0;31mFatal Error: ");
    ft_printf(str);
    ft_printf("\n\e[0;37m");
    return (1);
}

void close_window(t_global *g)
{
    if (g->mlx_win != NULL)
        mlx_destroy_window(g->mlx, g->mlx_win);
    clear_image_memory(g);
    if (g->mlx != NULL)
        free(g->mlx);
    system("leaks fractol");
    exit(1);
}