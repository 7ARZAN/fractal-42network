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

#include "../fractol.h"

//get_color function to get the color of each pixel !
void	ft_get_color(t_data *data)
{
	data->color_code++;
	if (data->color_code == 8)
		data->color_code = 0;
	if (data->color_code == 0)
		data->color = 0xff0801;
	else if (data->color_code == 1)
		data->color = 0xfff600;
	else if (data->color_code == 2)
		data->color = 0x18ff00;
	else if (data->color_code == 3)
		data->color = 0xf4f4f5;
	else if (data->color_code == 4)
		data->color = 0xb0ffd9;
	else if (data->color_code == 5)
		data->color = 0xffffd9;
	else if (data->color_code == 6)
		data->color = 0xFFFCA7;
	else if (data->color_code == 7)
		data->color = 0xf1f1e1;
}

//ft_key_hook2 function to handle the key events !
void	ft_key_hook2(t_data *data, int keycode)
{
	if (keycode == 35)
		data->julia = !data->julia;
	if (keycode == 15)
	{
		data->zoom = 2;
		data->ox = 0;
		data->oy = 0;
		data->julia_move = 0;
		data->color_code = 0;
	}
	else if (keycode == 45)
		data->max_it -= 10;
	else if (keycode == 6)
		data->max_it += 10;
	else if (keycode == 8)
		ft_get_color(data);
	else if (keycode == 49)
		data->julia_move = !data->julia_move;
}

//ft_key_hook function to handle the key events !
//keycode == 53 || keycode == 12 to exit the program !
//keycode == 126 || keycode == 125 || keycode == 124 ||
//keycode == 123 to move the fractal !
int	ft_key_hook(int keycode, void *param)
{
	t_data	*data;

	data = param;
	if (keycode == 53 || keycode == 12)
		exit(0);
	else if (keycode == 126)
		data->oy -= data->zoom / 10;
	else if (keycode == 125)
		data->oy += data->zoom / 10;
	else if (keycode == 124)
		data->ox += data->zoom / 10;
	else if (keycode == 123)
		data->ox -= data->zoom / 10;
	ft_key_hook2(data, keycode);
	if (keycode == 35 || keycode == 15 || keycode == 45 || keycode == 6
		|| keycode == 126 || keycode == 125 || keycode == 124 || keycode == 123)
		ft_draw(*data);
	return (0);
}

//ft_mouse_zoom function to handle the mouse events !
//button == 5 to zoom in ! button == 4 to zoom out !
//x and y are the coordinates of the mouse !
//new_ox and new_oy are the new coordinates of the mouse !
//we use ft_map function to map the coordinates of the mouse !
void	ft_mouse_zoom(t_data *data, int button, int x, int y)
{
	double	new_ox;
	double	new_oy;

	new_ox = ft_map(x, data->ox - (data->zoom * 0.128), data->ox + (data->zoom
				* 0.128));
	new_oy = ft_map(y, data->oy - (data->zoom * 0.128), data->oy + (data->zoom
				* 0.128));
	data->ox = new_ox;
	data->oy = new_oy;
	if (button == 5)
		data->zoom -= data->zoom * 0.1;
	else if (button == 4)
		data->zoom += data->zoom * 0.1;
}

//ft_mouse_hook function to handle the mouse events !
//button == 1 to switch between moving and not moving the julia !
int	ft_mouse_hook(int button, int x, int y, void *param)
{
	t_data	*data;

	data = param;
	if (button != 1 && button != 2)
	{
		ft_mouse_zoom(data, button, x, y);
		ft_draw(*data);
	}
	else if (button == 1 && data->julia)
		data->julia_move = !data->julia_move;
	return (0);
}
