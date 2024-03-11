/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 08:43:23 by databey           #+#    #+#             */
/*   Updated: 2024/03/07 15:52:06 by databey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void clear_image_memory(t_global *g)
{
    if (g)
    {
        if (g->img)
        {
            if (g->img->addr)
                free(g->img->addr);
            free(g->img);
         }
    }
}

void close_window(t_global *g)
{
    if (g->mlx_win != NULL)
        mlx_destroy_window(g->mlx, g->mlx_win);
    clear_image_memory(g);
    if (g->mlx != NULL)
        free(g->mlx);
    exit(1);
}