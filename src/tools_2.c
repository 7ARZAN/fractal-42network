
#include "../inc/fractol.h"

void	fractal_starter1(t_event *event)
{
	if (event->num == 1)
	{
		event->t_c = 1;
		event->zoom = 200;
		event->zoom_ol = 200;
		event->it = 50;
		event->mvx = -2;
		event->mvy = -1.24;
		event->trx = 0;
		event->try = 0;
	}
	if (event->num == 2)
	{
		event->x = 240;
		event->y = 390;
		event->lock = 0;
		event->zoom = 150;
		event->zoom_ol = 150;
		event->it = 50;
		event->mvx = -2;
		event->mvy = -2;
		event->trx = 0;
		event->try = 0;
	}
}

void	fractal_starter2(t_event *event)
{
	if (event->num == 3)
	{
		event->zoom = 200;
		event->zoom_ol = 200;
		event->it = 50;
		event->mvx = -2;
		event->mvy = -1.90;
		event->trx = 0;
		event->try = 0;
	}
	if (event->num == 4)
	{
		event->t_c = -1;
		event->zoom = 220;
		event->zoom_ol = 220;
		event->it = 50;
		event->mvx = -1.7;
		event->mvy = -1.50;
		event->trx = 0;
		event->try = 0;
	}
}

void	fractal_starter3(t_event *event)
{
	if (event->num == 5)
	{
		event->t_c = 1;
		event->zoom = 160;
		event->zoom_ol = 160;
		event->it = 50;
		event->mvx = -1.9;
		event->mvy = -1.9;
		event->trx = 0;
		event->try = 0;
	}
}

void	fractal_starter(t_event *event)
{
	if (event->c == 0)
		event->c = 0x030449;
	fractal_starter1(event);
	fractal_starter2(event);
	fractal_starter3(event);
	if (event->num == 6)
	{
		event->t_c = 1;
		event->zoom = 140;
		event->zoom_ol = 140;
		event->it = 50;
		event->mvx = -2.1;
		event->mvy = -2.1;
		event->trx = 0;
		event->try = 0;
	}
}
