#include "../includes/fractol.h"

void	erase_img(int *tab)
{
	int	i;

	i = 0;
	while (i < 600 * 600)
	{
		tab[i] = 0x000000;
		i++;
	}
}

void	close_it(t_event *event)
{
	mlx_destroy_image(event->ptr.mlx, event->img.ptr);
	mlx_clear_window(event->ptr.mlx, event->ptr.win);
	mlx_destroy_window(event->ptr.mlx, event->ptr.win);
	exit(0);
}

int	call_closer(void *param)
{
	t_event	*event;

	event = (t_event *)param;
	close_it(event);
	return (0);
}

void	call_the_fractal(int num, t_event *event)
{
	event.num = num;
	fractal_starter(event);
}
