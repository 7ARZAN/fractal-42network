#include "../includes/fractol.h"

void  mandelbrot_core(t_dep *dep, t_set var)
{
  var.x = 0;
  while (var.x < 600)
  {
    var.cr = (double) (var.x + dep->event.trx) / (dep->event.zoom) + dep->event.mvx;
    var.ci = (double) (var.y + dep->event.try) / (dep->event.zoom) + dep->event.mvy;
    var.zr = 0;
    var.zi = 0;
    var.i = 0;
    while (var.zr * var.zr + var.zi * var.zi < 4 && var.i < dep->event.it)
    {
      var.tmp = var.zr;
      var.zr = var.zr * var.zr - var.zi * var.zi + var.cr;
      var.zi = det->event.t_c * 2 * var.zi * var.tmp + var.ci;
      var.i++;
    }
    if (var.i < dep->event.it)
      dep->tab[var.x + var.y * 600] = dep->event.c * var.i;
    var.x++;
  }
}

void  *mandelbrot_part1(void *param)
{
  t_dep *dep;
  t_set var;

  dep = (t_dep *)param;
  var.y = 0;
  while (var.y < 150)
  {
      mandelbrot_core(dep, var);
      var.y++;
  }
  return (NULL);
}

void  *mandelbrot_part2(void *param)
{
  t_dep *dep;
  t_set var;

  dep = (t_dep *)param;
  var.y = 150;
  while (var.y < 300)
  {
      mandelbrot_core(dep, var);
      var.y++;
  }
  return (NULL);
}

void  *mandelbrot_part3(void *param)
{
  t_dep *dep;
  t_set var;

  dep = (t_dep *)param;
  var.y = 300;
  while (var.y < 450)
  {
      mandelbrot_core(dep, var);
      var.y++;
  }
  return (NULL);
}

void  *mandelbrot_part4(void *param)
{
  t_dep *dep;
  t_set var;

  dep = (t_dep *)param;
  var.y = 450;
  while (var.y < 600)
  {
      mandelbrot_core(dep, var);
      var.y++;
  }
  return (NULL);
}
