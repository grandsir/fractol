/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:27:27 by databey           #+#    #+#             */
/*   Updated: 2024/03/05 13:07:30 by databey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <time.h>
# include "mlx.h"
# include "actions.h"
# include "../libft/includes/libft.h"
# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 720
# define RE_START -2
# define RE_END 1
# define IM_START -1
# define IM_END 1
# define MAX_ITER 100

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_event_data {
	int 	mouse_pan_x;
	int 	mouse_x;
	int 	mouse_y;
	int 	mouse_pan_y;
	int		mouse_hold; 
	double	world_scale;
}	t_edata;

typedef struct s_global {
	double		offset_x;
	double		offset_y;
	void 	*mlx;
	void	*mlx_win;
	int		palette;
	t_data	*img;
	t_edata event;
}				t_global;

int		setup_mouse_events(t_global *g);
int		mandelbrot(double c);
int		setup_keys(int keycode, t_global *g);
void	print_mandelbrot(t_global *g);
void	scale(t_global *g, int x, int y, double scale);
void	move(t_global *g, int x, int y);
void	mlx_safe_pixel_put(t_data *data, int x, int y, int color);
void	setup_global(void *mlx, void *mlx_win, t_global *g);
void	screen_to_world(t_global *g, int screen_x, int screen_y, int *world_x, int *world_y);
int		palette(t_global *g, int m);
void	init_image(t_global *g);
#endif
