/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 08:43:23 by databey           #+#    #+#             */
/*   Updated: 2024/03/05 13:15:07 by databey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void close_window(t_global *g)
{
    if (g)
    {
        if (g->img)
        {
            free(global->img->addr);
            free(global->img);
        }
        free(g);
    }
}