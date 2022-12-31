#include "../includes/fractol.h"

void	mandelbrot_set(int *tab, t_event event)
{
	t_dep	var;
	int		i;

	i = 0;
	var.event = event;
	var.tab = tab;
	pthread_create(&event.core[0], NULL, mandelbrot_part1, (void *)&var);
	pthread_create(&event.core[0], NULL, mandelbrot_part2, (void *)&var);
	pthread_create(&event.core[0], NULL, mandelbrot_part3, (void *)&var);
	pthread_create(&event.core[0], NULL, mandelbrot_part4, (void *)&var);
	while (i < 4)
	{
		pthread_join(event.core[i], NULL);
		i++;
	}
}

void	julia_set(int *tab, t_event event)
{
	t_dep	var;
	int		i;

	i = 0;
	var.event = event;
	var.tab = tab;
	pthread_create(&event.core[0], NULL, julia_part1, (void *)&var);
	pthread_create(&event.core[0], NULL, julia_part2, (void *)&var);
	pthread_create(&event.core[0], NULL, julia_part3, (void *)&var);
	pthread_create(&event.core[0], NULL, julia_part4, (void *)&var);
	while (i < 4)
	{
		pthread_join(event.core[i], NULL);
		i++;
	}
}

void	burning_ship_set(int *tab, t_event event)
{
	t_dep	var;
	int		i;

	i = 0;
	var.event = event;
	var.tab = tab;
	pthread_create(&event.core[0], NULL, burning_ship_part1, (void *)&var);
	pthread_create(&event.core[0], NULL, burning_ship_part2, (void *)&var);
	pthread_create(&event.core[0], NULL, burning_ship_part3, (void *)&var);
	pthread_create(&event.core[0], NULL, burning_ship_part4, (void *)&var);
	while (i < 4)
	{
		pthread_join(event.core[i], NULL);
		i++;
	}
}

void	multibrot1_set(int *tab, t_event event)
{
	t_dep	var;
	int		i;

	i = 0;
	var.event = event;
	var.tab = tab;
	pthread_create(&event.core[0], NULL, multibrot1_part1, (void *)&var);
	pthread_create(&event.core[0], NULL, multibrot1_part2, (void *)&var);
	pthread_create(&event.core[0], NULL, multibrot1_part3, (void *)&var);
	pthread_create(&event.core[0], NULL, multibrot1_part4, (void *)&var);
	while (i < 4)
	{
		pthread_join(event.core[i], NULL);
		i++;
	}
}

void	multibrot2_set(int *tab, t_event event)
{
	t_dep	var;
	int		i;

	i = 0;
	var.event = event;
	var.tab = tab;
	pthread_create(&event.core[0], NULL, multibrot2_part1, (void *)&var);
	pthread_create(&event.core[0], NULL, multibrot2_part2, (void *)&var);
	pthread_create(&event.core[0], NULL, multibrot2_part3, (void *)&var);
	pthread_create(&event.core[0], NULL, multibrot2_part4, (void *)&var);
	while (i < 4)
	{
		pthread_join(event.core[i], NULL);
		i++;
	}
}
