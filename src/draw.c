/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 06:07:37 by elakhfif          #+#    #+#             */
/*   Updated: 2023/05/23 07:49:05 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void compute_pixel(t_fractal *fractal, int x, int y)
{
	fractal->complex.real = map_coord(x, fractal->offset_x - fractal->zoom,
		fractal->offset_x + fractal->zoom);
	fractal->complex.imag = map_coord(y, fractal->offset_y - fractal->zoom,
		fractal->offset_y + fractal->zoom);
	if (!fractal->is_julia)
	{
		fractal->complex.real_const = fractal->complex.real;
		fractal->complex.imag_const = fractal->complex.imag;
	}
	fractal->complex.iterations = 0;
}

void iterate_fractal(t_fractal *fractal)
{
	double real_temp;
	double imag_temp;

	while (fractal->complex.iterations < fractal->max_iterations)
	{
		real_temp = fractal->complex.real * fractal->complex.real -
			fractal->complex.imag * fractal->complex.imag;
		imag_temp = 2 * fractal->complex.real * fractal->complex.imag;
		if (fractal->is_burning_ship)
			imag_temp = fabs(imag_temp);
		fractal->complex.real = real_temp + fractal->complex.real_const;
		fractal->complex.imag = imag_temp + fractal->complex.imag_const;
		fractal->complex.iterations++;
		if (fractal->complex.real * fractal->complex.real +
			fractal->complex.imag * fractal->complex.imag > 4)
			break ;
	}
}

void set_pixel(t_fractal *fractal, int x, int y, int color)
{
	char	*pixel;

	pixel = fractal->img.data + (y * fractal->img.line_len +
		x * (fractal->img.bpp / 8));
	*(unsigned int *)pixel = color;
}

void render_fractal(t_fractal *fractal)
{
	int x;
	int y;
	int color;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			compute_pixel(fractal, x, y);
			iterate_fractal(fractal);
			color = fractal->complex.iterations * fractal->color;
			if (fractal->complex.iterations == fractal->max_iterations)
				color = 0;
			set_pixel(fractal, x, y, color);
			x++;
		}
		y++;
	}
	mlx_clear_window(fractal->mlx, fractal->window);
	mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->img.ptr, 0, 0);
}
