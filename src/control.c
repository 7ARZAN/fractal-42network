/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 06:07:30 by elakhfif          #+#    #+#             */
/*   Updated: 2024/12/26 00:32:53 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void cycle_color(t_fractal *fractal)
{
	const int colors[] = {0xff0801, 0xfff600, 0x18ff00, 0xf4f4f5,
		0xb0ffd9, 0xffffd9, 0xFFFCA7, 0xf1f1e1};

	fractal->color_scheme = (fractal->color_scheme + 1) % 8;
	fractal->color = colors[fractal->color_scheme];
}

void handle_key_additional(t_fractal *fractal, int keycode)
{
	if (keycode == P_KEY)
		fractal->is_julia = !fractal->is_julia;
	else if (keycode == R_KEY)
	{
		fractal->zoom = 2.0;
		fractal->offset_x = 0;
		fractal->offset_y = 0;
		fractal->julia_dynamic = 0;
		fractal->color_scheme = 0;
	}
	else if (keycode == N_KEY)
		fractal->max_iterations -= 10;
	else if (keycode == Z_KEY)
		fractal->max_iterations += 10;
	else if (keycode == C_KEY)
		cycle_color(fractal);
	else if (keycode == SPACE_KEY)
		fractal->julia_dynamic = !fractal->julia_dynamic;
}

int handle_key(int keycode, t_fractal *fractal)
{
	if (keycode == ESC_KEY || keycode == Q_KEY)
		close_window(fractal);
	else if (keycode == UP_KEY)
		fractal->offset_y -= fractal->zoom / 10;
	else if (keycode == DOWN_KEY)
		fractal->offset_y += fractal->zoom / 10;
	else if (keycode == RIGHT_KEY)
		fractal->offset_x += fractal->zoom / 10;
	else if (keycode == LEFT_KEY)
		fractal->offset_x -= fractal->zoom / 10;
	handle_key_additional(fractal, keycode);
	if (keycode == P_KEY || keycode == R_KEY || keycode == N_KEY ||
		keycode == Z_KEY || keycode == C_KEY || keycode == UP_KEY ||
		keycode == DOWN_KEY || keycode == RIGHT_KEY || keycode == LEFT_KEY)
		render_fractal(fractal);
	return (0);
}

void zoom_mouse(t_fractal *fractal, int button, int x, int y)
{
	double	new_x;
	double	new_y;

	new_x = map_coord(x, fractal->offset_x - (fractal->zoom * 0.128),
		fractal->offset_x + (fractal->zoom * 0.128));
	new_y = map_coord(y, fractal->offset_y - (fractal->zoom * 0.128),
		fractal->offset_y + (fractal->zoom * 0.128));
	fractal->offset_x = new_x;
	fractal->offset_y = new_y;
	if (button == MOUSE_SCROLL_DOWN)
		fractal->zoom -= fractal->zoom * 0.1;
	else if (button == MOUSE_SCROLL_UP)
		fractal->zoom += fractal->zoom * 0.1;
}

int handle_mouse(int button, int x, int y, t_fractal *fractal)
{
	if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
	{
		zoom_mouse(fractal, button, x, y);
		render_fractal(fractal);
	}
	else if (button == MOUSE_LEFT && fractal->is_julia)
		fractal->julia_dynamic = !fractal->julia_dynamic;
	return (0);
}
