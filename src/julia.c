#include "../includes/fractol.h"

void	julia_core(t_dep *dep, t_set var)
{
	static double	cr;
	static double	ci;

	var.x = -1;
	while (var.x++ < HEIGHT)
	{
		var.zr = (double)(var.x + dep->event.trx) / (dep->event.zoom)
			+ dep->event.mvx;
		var.zi = (double)(var.y + dep->event.try) / (dep->event.zoom)
			+ dep->event.mvy;
		if (dep->event.lock == 0)
		{
			cr = dep->event.x / (dep->event.zoom) + dep->event.mvx;
			ci = dep->event.y / (dep->event.zoom) + dep->event.mvy;
		}
		var.i = 0;
		while (var.zr * var.zr + var.zi * var.zi < 4 && var.i++ < dep->event.it)
		{
			var.tmp = var.zr;
			var.zr = var.zr * var.zr - var.zi * var.zi + cr;
			var.zi = 2 * var.zi * var.tmp + ci;
		}
		if (var.i < dep->event.it)
			dep->tab[var.x + var.y * 600] = dep->event.c * var.i;
	}
}

void	*julia_part1(void *param)
{
	t_dep	*dep;
	t_set	var;

	dep = (t_dep *)param;
	var.y = 0;
	while (var.y < 150)
	{
		julia_core(dep, var);
		var.y++;
	}
	return (NULL);
}

void	*julia_part2(void *param)
{
	t_dep	*dep;
	t_set	var;

	dep = (t_dep *)param;
	var.y = 150;
	while (var.y < 300)
	{
		julia_core(dep, var);
		var.y++;
	}
	return (NULL);
}

void	*julia_part3(void *param)
{
	t_dep	*dep;
	t_set	var;

	dep = (t_dep *)param;
	var.y = 300;
	while (var.y < 450)
	{
		julia_core(dep, var);
		var.y++;
	}
	return (NULL);
}

void	*julia_part4(void *param)
{
	t_dep	*dep;
	t_set	var;

	dep = (t_dep *)param;
	var.y = 450;
	while (var.y < 600)
	{
		julia_core(dep, var);
		var.y++;
	}
	return (NULL);
}
