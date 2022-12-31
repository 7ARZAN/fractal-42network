#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <math.h>
# include <pthread.>

# define WIDTH 600
# define HEIGHT 600

typedef struct s_ptr
{
	void		*mlx;
	void		*win;
}				t_ptr;

typedef struct s_img
{
	int			bpp;
	int			sl;
	int			end;
	void		*ptr;
	int			*data;
}				t_img;

typedef struct s_event
{
	t_ptr		ptr;
	t_img		img;
	double		x;
	double		y;
	double		zoom;
	double		zoom_ol;
	int			it;
	double		mvx;
	double		mvy;
	int			num;
	int			lock;
	double		trx;
	double		try;
	int			t_c;
	int			c;
	pthread_t	core[8];
}				t_event;

typedef struct s_zoom
{
	double		cx;
	double		cy;
	double		nx;
	double		ny;
}				t_zoom;

typedef struct s_set
{
	int			i;
	int			x;
	int			y;
	double		zr;
	double		zi;
	double		cr;
	double		ci;
	double		tmp;
	double		zr_nom;
	double		zr_den;
	double		zi_nom;
}				t_set;

typedef struct s_dep
{
	int			*tab;
	t_event		event;
	int			a;
	int			b;
}				t_dep;

void			erase_img(int *tab);
int				key_press(int keycode, void *param);
int				mouse_press(int code, int x, int y, void *param);
void			draw(int *tab, t_event event, int num);
void			call_the_fractal(int num, t_event *event);
void			fractal_starter(t_event *event);
int				mouse_move(int x, int y, void *param);
void			mandelbrot_set(int *tab, t_event event);
void			burning_ship_set(int *tab, t_event event);
void			julia_set(int *tab, t_event event);
void			multibrot1_set(int *tab, t_event event);
void			multibrot2_set(int *tab, t_event event);
void			*burning_ship_part1(void *param);
void			*burning_ship_part2(void *param);
void			*burning_ship_part3(void *param);
void			*burning_ship_part4(void *param);
void			*mandelbrot_part1(void *param);
void			*mandelbrot_part2(void *param);
void			*mandelbrot_part3(void *param);
void			*mandelbrot_part4(void *param);
void			*julia_part1(void *param);
void			*julia_part2(void *param);
void			*julia_part3(void *param);
void			*julia_part4(void *param);
void			*multibrot1_part1(void *param);
void			*multibrot1_part2(void *param);
void			*multibrot1_part3(void *param);
void			*multibrot1_part4(void *param);
void			*multibrot2_part1(void *param);
void			*multibrot2_part2(void *param);
void			*multibrot2_part3(void *param);
void			*multibrot2_part4(void *param);
void			close_it(t_event *event);
int				call_closer(void *param);
void			key_change(int keycode, t_event *event);
void			key_color(int keycode, t_event *event);
void			zoom_in(int x, int y, t_event *event);
void			zoom_out(int x, int y, t_event *event);

#endif
