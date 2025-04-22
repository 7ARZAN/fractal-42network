/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 05:40:31 by elakhfif          #+#    #+#             */
/*   Updated: 2023/05/23 07:50:06 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 600
# define HEIGHT 600
# define ESC_KEY 53
# define Q_KEY 12
# define UP_KEY 126
# define DOWN_KEY 125
# define RIGHT_KEY 124
# define LEFT_KEY 123
# define P_KEY 35
# define R_KEY 15
# define N_KEY 45
# define Z_KEY 6
# define C_KEY 8
# define SPACE_KEY 49
# define MOUSE_SCROLL_UP 4
# define MOUSE_SCROLL_DOWN 5
# define MOUSE_LEFT 1

typedef struct s_image
{
	void	*ptr;
	char	*data;
	int		bpp;
	int		line_len;
	int		endian;
}			t_image;

typedef struct s_complex
{
	double	real;
	double	imag;
	double	real_const;
	double	imag_const;
	int		iterations;
}			t_complex;

typedef struct s_fractal
{
	void		*mlx;
	void		*window;
	t_image		img;
	t_complex	complex;
	double		zoom;
	double		offset_x;
	double		offset_y;
	int			max_iterations;
	int			color;
	int			color_scheme;
	int			is_julia;
	int			julia_dynamic;
	int			is_burning_ship;
}				t_fractal;

double		map_coord(int input, double min, double max);
void		compute_pixel(t_fractal *fractal, int x, int y);
void		iterate_fractal(t_fractal *fractal);
void		set_pixel(t_fractal *fractal, int x, int y, int color);
void		render_fractal(t_fractal *fractal);
void		cycle_color(t_fractal *fractal);
int			parse_int(char *str);
int			close_window(t_fractal *fractal);
void		display_instructions(void);
double		parse_float(char *str);
void		handle_key_additional(t_fractal *fractal, int keycode);
int			handle_key(int keycode, t_fractal *fractal);
void		zoom_mouse(t_fractal *fractal, int button, int x, int y);
int			handle_mouse(int button, int x, int y, t_fractal *fractal);
void		init_julia_with_args(char **argv);

#endif
