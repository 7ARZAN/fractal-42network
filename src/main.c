#include "../includes/fractol.h"

void  draw(int *tab, t_event, int num)
{
  if (num == 1)
    mandelbrot_set(tab, event);
  if (num == 2)
    julia_set(tab, event);
  if (num == 3)
    burning_ship_set(tab, event);
  if (num == 4)
    madelbrot_set(tab, event);
  if (num == 5)
    multibrot1_set(tab, event);
  if (num == 6)
    multibrot2_set(tab, event);
  mlx_put_image_to_window(event.ptr.mlx, event.ptr.win, event.img.ptr, 0, 0);
}

void  usage(void)
{
  ft_putchar('\n');
  ft_putendl(" ISTA3MIL : ./fractol [ism chakl ladi toridoh]");
  ft_putchar('\n');
  ft_putendl(" [+] Mandelbrot");
  ft_putendl(" [+] Julia");
  ft_putendl(" [+] Burning Ship");
  ft_putendl(" [+] Tricorn");
  ft_putendl(" [+] Multibrot1");
  ft_putendl(" [+] Multibrot2");
  exit(0);
}

void  choose_fractal(char *s, t_event *event)
{
  if (!ft_strcmp(s, "Mandelbrot"))
    call_the_fractal(1, event);
  else if (!ft_strcmp(s, "Julia"))
    call_the_fractal(2, event);
  else if (!ft_strcmp(s, "Burning Ship"))
    call_the_fractal(3, event);
  else if (!ft_strcmp(s, "Tricorn"))
    call_the_fractal(4, event);
  else if (!ft_strcmp(s, "Multibrot1"))
    call_the_fractal(5, event);
  else if (!ft_strcmp(s, "Multibrot2"))
    call_the_fractal(6, event);
  else
    usage();
}

void  the_key(t_ptr ptr)
{
  int x;
  int y;

  x = 599;
  while (++x < WIDTH + 300)
  {
    y = -1;
    while (++y < HEIGHT)
      mlx_pixel_put(ptr.mlx, ptr.win, x, y, 0xDBDBDB);
  }
  // PART OF PITING STRING WITH Minilibx.
  // press esc to exit
  // M : for Mandelbrot
  // J : Julia
  // T : Tricorn
  // A : Multibrot
  // Z : Multibrot
  // Scroll Up to Zoom In
  // Scroll Down to Zoom Out
  // Use Arrows to move map
  // from 1 to 6 to change colors
  // AAAAAAAAAAAAAAAAAACH HAD L9LAWI HADA :((((((
}

int main(int ac, char **av)
{
  t_ptr ptr;
  t_img img;
  t_event event;

  if (ac != 2)
    usage();
  choose_fractal(av[1], &event);
  ptr.mlx = mlx_init();
  ptr.win = mlx_new_window(ptr.mlx, WIDTH + 300, HEIGHT, "Fractol");
  img.ptr = mlx_new_image(ptr.mlx, WIDTH, HEIGHT);
  the_key(ptr);
  img.data = (int *)mlx_get_data_addr(img.ptr, &img.bpp, &img.sl, &img.end);
  event.ptr = ptr;
  event.img = img;
  draw(img.data, event, event.num);
  mlx_hook(ptr.win, 2, 0, key_press, (void *)&event);
  mlx_hook(ptr.win, 4, 0, mouse_press, (void *)&event);
  mlx_hook(ptr.win, 6, 0, mouse_move, (void *)&event);
  mlx_hook(ptr.win, 17, 0, call_closer, (void *)&event);
  mlx_loop(ptr,mlx);
}
