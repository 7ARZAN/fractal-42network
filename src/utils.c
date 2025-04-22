/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 05:40:27 by elakhfif          #+#    #+#             */
/*   Updated: 2024/12/25 20:39:10 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int parse_int(char *str)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	while (str[i])
		result = result * 10 + (str[i++] - '0');
	return (result);
}

double map_coord(int input, double min, double max)
{
	return (input * ((max - min) / WIDTH) + min);
}

int close_window(t_fractal *fractal)
{
	mlx_destroy_window(fractal->mlx, fractal->window);
	exit(0);
	return (0);
}

double parse_float(char *str)
{
	int		i = 0;
	int		sign = 1;
	double	result = 0;
	int		divider = 1;

	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] && str[i] != '.')
		result = result * 10 + (str[i++] - '0');
	if (str[i++] == '.')
	{
		while (str[i])
		{
			result = result * 10 + (str[i++] - '0');
			divider *= 10;
		}
	}
	return (result * sign / divider);
}

void display_instructions(void)
{
	const char *instructions[] = {
		"############## INSTRUCTIONS ##############\n",
		"# Mouse wheel: Zoom in/out               #\n",
		"# Mouse left: Toggle Julia movement      #\n",
		"# Arrows: Move fractal                   #\n",
		"# R: Reset view                         #\n",
		"# C: Cycle colors                       #\n",
		"# P: Switch fractal type                #\n",
		"# Z: Increase iterations                #\n",
		"# N: Decrease iterations                #\n",
		"# ESC/Q: Quit                           #\n",
		"# Space: Toggle Julia dynamics          #\n",
		"############## INSTRUCTIONS ##############\n"
	};
	int	i;

	i = 0;
	while (i < 12)
		write(1, instructions[i++], 43);
}
