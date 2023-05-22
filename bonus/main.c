/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 06:07:42 by elakhfif          #+#    #+#             */
/*   Updated: 2023/05/22 12:47:36 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

char	*ft_get_title(int fractol)
{
	if (fractol == 1)
		return ("FRACTOLL - Mandelbrot");
	else if (fractol == 2)
		return ("FRACTOLL - Julia");
	return ("FRACTOLL - Burning ship");
}

//ft_init function to initialize the data structure with the values of the fractal choosen by the user !
//and initialize the mlx window and the image
void	ft_init(t_data *data, int fractol)
{
	data->cnx = mlx_init();
	data->window = mlx_new_window(data->cnx, 600, 600, ft_get_title(fractol));
	data->max_it = 100;
	data->ox = 0;
	data->oy = 0;
	data->zoom = 2;
	data->image.img = mlx_new_image(data->cnx, 600, 600);
	data->image.address = mlx_get_data_addr(data->image.img,
			&data->image.bits_per_pixel, &data->image.line_length,
			&data->image.endian);
	data->color = 0xff801;
	data->color_code = 0;
	data->julia = (fractol == 2);
	data->burning_ship = (fractol == 3);
	data->julia_move = 0;
	data->var.a_r = -0.466;
	data->var.b_r = 0.622;
}

//fun function to move the julia set with the mouse movement 
//and draw it again with the new values of a_r and b_r
int	fun(int x, int y, t_data *data)
{
	if (x >= 0 && x <= 600 && y >= 0 && y <= 600 && data->julia_move) //check if the mouse is inside the window and if the julia set is activated
	{
		data->var.a_r = ft_map(x, data->ox - data->zoom, data->ox + data->zoom); //map the x value to the real part of the complex number
		data->var.b_r = ft_map(y, data->oy - data->zoom, data->oy + data->zoom); //map the y value to the imaginary part of the complex number
		ft_draw(*data);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_data	data;
	int		number;

	if (ac == 2)
	{
		number = ft_atoi(av[1]);
		if (number == 1 || number == 2 || number == 3)
		{
			ft_instructions();
			ft_init(&data, number);
			ft_draw(data);
			mlx_key_hook(data.window, ft_key_hook, &data);
			mlx_mouse_hook(data.window, ft_mouse_hook, &data);
			mlx_hook(data.window, 6, 0, fun, &data);
			mlx_hook(data.window, 17, 0, ft_close, &data);
			mlx_loop(data.cnx);
		}
	}
	write(1, "##############  'Fractals'  ###############\n", 44);
	write(1, "# 1 - <Mandelbrot>                        #\n", 44);
	write(1, "# 2 - <Julia>                             #\n", 44);
	write(1, "# 3 - <burning_ship>                      #\n", 44);
	write(1, "##############  'Fractals'  ###############\n", 44);
	return (0);
}
