/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:27:27 by databey           #+#    #+#             */
/*   Updated: 2024/02/26 04:41:07 by databey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <math.h>
# include <time.h>
# include "mlx.h"
# include "../libft/includes/libft.h"
# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_event_data {
	int 	mouse_pan_x;
	int 	mouse_pan_y;
	int		mouse_hold;
	float	world_scale;
}	t_edata;

typedef struct s_global {
	float		offset_x;
	float		offset_y;
	void 	*mlx;
	void	*mlx_win;
	t_data	*img;
	t_edata event;
}				t_global;

int		convert_to_real_coordinate_x(t_global *g, int x);
int		convert_to_real_coordinate_y(t_global *g, int y);
void	mlx_safe_pixel_put(t_data *data, int x, int y, int color);
int		render_next_frame(void *);
int		setup_mouse_events(t_global *g);
void	setup_global(void *mlx, void *mlx_win, t_global *g);
void	fill(t_global *g, int x, int y, int width, int height, int col);
void	world_to_screen(t_global *g, int world_x, int world_y, int *screen_x, int *screen_y);
void	screen_to_world(t_global *g, int screen_x, int screen_y, int *world_x, int *world_y);
void	draw_line(t_global *g, int sx, int sy, int ex, int ey);
void	init_image(t_global *g);
#endif
