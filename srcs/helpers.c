/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 08:43:23 by databey           #+#    #+#             */
/*   Updated: 2024/02/26 01:00:08 by databey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fill(t_global *g, int x, int y, int width, int height, int col)
{
	t_data	img;
	img.img = mlx_new_image(g->mlx, width, height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	int w;
	int h;							
	w = 0;
	h = 0;
	while (h < height)
	{
		while (w < width)
		{
			mlx_safe_pixel_put(&img, w, h, col);
			w++;
		}
		h++;
	}
	mlx_put_image_to_window(g->mlx, g->mlx_win, img.img, 0, 0);
}

void draw_line(t_global *g, int sx, int sy, int ex, int ey) {
    int dx = ex - sx;
    int dy = ey - sy;
    int isx = sx; 
    int isy = sy; 

    int width = abs(dx) + 1; 
    int height = abs(dy) + 1;

    if (dx == 0 && dy == 0) {
        mlx_safe_pixel_put(g->img, sx, sy, 0x00FF0000);
    } else {
        int step_x = (dx > 0) ? 1 : -1;
        int step_y = (dy > 0) ? 1 : -1;

        dx = abs(dx); 
        dy = abs(dy);

        if (dx >= dy) {
            int error = dx / 2;
            int y = sy;

            for (int x = sx; x != ex; x += step_x) {
                mlx_safe_pixel_put(g->img, x, y, 0x00FF0000);
                error -= dy;
                if (error < 0) {
                    y += step_y;
                    error += dx;
                }
            }
        } else {
            int error = dy / 2;
            int x = sx;

            for (int y = sy; y != ey; y += step_y) {
                mlx_safe_pixel_put(g->img, x, y, 0x00FF0000);
                error -= dx;
                if (error < 0) {
                    x += step_x;
                    error += dy;
                }
            }
        }
    }
}