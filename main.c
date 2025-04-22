/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 05:38:08 by elakhfif          #+#    #+#             */
/*   Updated: 2023/05/23 07:31:52 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

char *get_window_title(int fractal_type)
{
	if (fractal_type == 1)
		return ("FRACTOL - Mandelbrot");
	else if (fractal_type == 2)
		return ("FRACTOL - Julia");
	return ("FRACTOL - Burning Ship");
}

void init_fractal(t_fractal *fractal, int fractal_type)
{
	fractal->mlx = mlx_init();
	fractal->window = mlx_new_window(fractal->mlx, WIDTH, HEIGHT,
		get_window_title(fractal_type));
	fractal->max_iterations = 100;
	fractal->offset_x = 0;
	fractal->offset_y = 0;
	fractal->zoom = 2.0;
	fractal->img.ptr = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	fractal->img.data = mlx_get_data_addr(fractal->img.ptr, &fractal->img.bpp,
		&fractal->img.line_len, &fractal->img.endian);
	fractal->color = 0xff0801;
	fractal->color_scheme = 0;
	fractal->is_julia = (fractal_type == 2);
	fractal->is_burning_ship = (fractal_type == 3);
	fractal->julia_dynamic = 0;
	fractal->complex.real_const = -0.466;
	fractal->complex.imag_const = 0.622;
}

int update_julia(int x, int y, t_fractal *fractal)
{
	if (x >= 0 && x <= WIDTH && y >= 0 && y <= HEIGHT && fractal->julia_dynamic)
	{
		fractal->complex.real_const = map_coord(x, fractal->offset_x - fractal->zoom,
			fractal->offset_x + fractal->zoom);
		fractal->complex.imag_const = map_coord(y, fractal->offset_y - fractal->zoom,
			fractal->offset_y + fractal->zoom);
		render_fractal(fractal);
	}
	return (0);
}

void init_julia_with_args(char **argv)
{
	t_fractal fractal;

	display_instructions();
	init_fractal(&fractal, 2);
	fractal.complex.real_const = parse_float(argv[2]);
	fractal.complex.imag_const = parse_float(argv[3]);
	render_fractal(&fractal);
	mlx_key_hook(fractal.window, handle_key, &fractal);
	mlx_mouse_hook(fractal.window, handle_mouse, &fractal);
	mlx_hook(fractal.window, 6, 0, update_julia, &fractal);
	mlx_hook(fractal.window, 17, 0, close_window, &fractal);
	mlx_loop(fractal.mlx);
}

int main(int argc, char **argv)
{
	t_fractal	fractal;
	int			fractal_type;

	if (argc == 2)
	{
		fractal_type = parse_int(argv[1]);
		if (fractal_type >= 1 && fractal_type <= 3)
		{
			display_instructions();
			init_fractal(&fractal, fractal_type);
			render_fractal(&fractal);
			mlx_key_hook(fractal.window, handle_key, &fractal);
			mlx_mouse_hook(fractal.window, handle_mouse, &fractal);
			mlx_hook(fractal.window, 6, 0, update_julia, &fractal);
			mlx_hook(fractal.window, 17, 0, close_window, &fractal);
			mlx_loop(fractal.mlx);
		}
	}
	else if (argc == 4 && parse_int(argv[1]) == 2)
		init_julia_with_args(argv);
	write(1, "Usage:\t./fractol [1, 2, 3]\n", 28);
	write(1, "[1]:\tMandelbrot\n[2]:\tJulia\n[3]:\tBurning Ship\n", 47);
	return (0);
}
