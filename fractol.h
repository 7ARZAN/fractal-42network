/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 05:40:31 by elakhfif          #+#    #+#             */
/*   Updated: 2023/05/22 06:18:57 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_image
{
	void	*img;
	char	*address;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_image;

typedef struct s_var
{
	double	a;
	double	b;
	double	aa;
	double	bb;
	double	a_r;
	double	b_r;
	int		num_it;
}			t_var;

typedef struct s_data
{
	void	*cnx;
	void	*window;
	t_image	image;
	t_var	var;
	double	zoom;
	double	ox;
	double	oy;
	int		max_it;
	int		color;
	int		color_code;
	int		julia;
	int		julia_move;
	int		burning_ship;
}			t_data;

double		ft_map(int in, double min, double max);
void		ft_pre_cal(t_data *data, int x, int y);
void		ft_calculater(t_data *data);
void		ft_mlx_pixel_put(t_data data, int x, int y, int color);
void		ft_draw(t_data data);
void		ft_get_color(t_data *data);
int			ft_atoi(char *num);
void		ft_get_color(t_data *data);
void		ft_key_hook2(t_data *data, int keycode);
int			ft_key_hook(int keycode, void *param);
void		ft_mouse_zoom(t_data *data, int button, int x, int y);
int			ft_mouse_hook(int button, int x, int y, void *param);
void		ft_instructions(void);

#endif
