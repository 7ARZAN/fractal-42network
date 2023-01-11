#include "fractol.h"

char  *ft_get_title(int fractol)
{
  if (fractol == 1)
    return ("FRACTOLL - Mandelbrot");
  else if (fractol == 2)
    return ("FRACTOLL - Julia");
  return ("FRACTOLL - Burning ship");
}

void  ft_init(t_data *data, int fractol)
{
  data->cnx = mlx_init();
  data->window = mlx_new_window(data->cnx, 600, 600, ft_get_title(fractol));
  data->max_it = 100;
  data->ox = 0;
  data->oy = 0;
  data->zoom = 2;
  data->image.img = mlx_new_image(data->cnx, 600, 600);
  data->image_address = mlx_get_data_addr(data->image.img,
      &data->image.bits_per_pixel, &data->image.line.length,
      &data->image.endian);
  data->color = 0xff801;
  data->color.code = 0;

  }
