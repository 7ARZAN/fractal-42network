#include "../includes/fractol.h"

void	key_change(int key_code, t_event *event)
{
	if (key_code == 46)
		call_the_fractal(1, event);
	if (key_code == 38)
		call_the_fractal(2, event);
	if (key_code == 11)
		call_the_fractal(3, event);
	if (key_code == 17)
		call_the_fractal(4, event);
	if (key_code == 0)
		call_the_fractal(5, event);
	if (key_code == 6)
		call_the_fractal(6, event);
}

void	key_color(int key_code, t_event *event)
{
	if (key_code == 83)
		event.c = ;
	if (key_code == 84)
		event.c = ;
	if (key_code == 85)
		event.c = ;
	if (key_code == 86)
		event.c = ;
	if (key_code == 87)
		event.c = ;
	if (key_code == 88)
		event.c = ;
}

void	zoom_out(int x, int y, t_event *event)
{
	double	cx;
	double	cy;
	double	nx;
	double	ny;

	x += event.trx;
	y += event.try;
	cx = x / event.zoom;
	cy = y / event.zoom;
	event.zoom /= 1.4;
	nx = x / event.zoom;
	ny = y / event.zoom;
	event.mvx -= nx - cx;
	event.mvy -= ny - cy;
	event.it -= 2;
}

void	zoom_in(int x, int y, t_event *event)
{
	double cx;
	double cy;
	double nx;
	double ny;

	x += event.trx;
	y += event.try;
	cx = x / event.zoom;
	cy = y / event.zoom;
	event.zoom *= 1.4;
	nx = x / event.zoom;
	ny = y / event.zoom;
	event.mvx -= nx - cx;
	event.mvy -= ny - cy;
	event.it += 2;
