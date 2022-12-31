
#include "../includes/fractol.h"

int	key_press(int keycode, void *param)
{
	t_event	*event;

	event = (t_event *)param;
	if (keycode == 53)
		close_it(event);
	if (keycode == 69)
		event->it += 10;
	if (keycode == 78 && event->it != 10)
		event->it -= 10;
	if (keycode == 126)
		event->try -= 4;
	if (keycode == 125)
		event->try += 4;
	if (keycode == 124)
		event->tryx += 4;
	if (keycode == 123)
		event->tryx -= 4;
	key_change(keycode, event);
	key_color(keycode, event);
	erase_img(event->img.data);
	draw(event->img.data, *event, event->num);
	return (0);
}

int	mouse_press(int code, int x, int y, void *param)
{
	t_event	*event;

	if (x > 600 || x < 0 || y > 600 || y < 0)
		return (0);
	event = (t_event *)param;
	if (code == 5 && event->zoom > event->zoom_ol)
		zoom_out(x, y, event);
	if (code == 4)
		zoom_in(x, y, event);
	if (code == 2)
	{
		if (event->lock == 1)
			event->lock = 0;
		else
			event->lock = 1;
	}
	erase_img(event->img.data);
	draw(event->img.data, *event, event->num);
	return (0);
}

int	mouse_move(int x, int y, void *param)
{
	t_event	*event;

	event = (t_event *)param;
	if (event->lock == 1)
		return (0);
	if (x <= 600 && x >= 0 && y <= 600 && y >= 0)
	{
		event->x = x;
		event->y = y;
	}
	erase_img(event->img.data);
	draw(event->img.data, *event, event->num);
	return (0);
}
