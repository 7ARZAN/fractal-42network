#include "../includes/fractol.h"

void  multibrot1_core(t_dep *dep, t_set var)
{
  var.x = 0;
  while (var.x < 600)
  {
    var.cr = (double)(var.x + dep->event.trx) / (dep->event.zoom) + dep->event.mvx;
    var.ci = (double)(var.y + dep->event.try) / (dep->event.zoom) + dep->event.mvy;
    var.zr = var.cr;
    var.zi = var.ci;
    var.i = 0;
    while (var.zr * var.zr + var.zi * var.zi < 4 && var.i < dep->event.it)
    {
      var.tmp = var.zr;
      var.zr = var.zr * var.zr * var.zr - 3 * var.zr * var.zi * var.zi + var.cr;
      var.zi = 3 * var.tmp * var.tmp * var.zi - var.zi * var.zi * var.zi + var.ci;
      var.i++;
    }
    if (var.i < dep->event.it)
      dep->tab[var.x + var.y * 600] = dep->event.c * var.i;
    var.x++;
  }
}

void  *multibrot1_part1(void *param)
{
  t_dep *dep;
  t_set var;

  dep = (t_dep *)param;
  var.y = 0;
  while (var.y < 150)
  {
      multibrot1_core(dep, var);
      var.y++;
  }
  return (NULL);
}

void  *multibrot1_part2(void *param)
{
  t_dep *dep;
  t_set var;

  dep = (t_dep *)param;
  var.y = 150;
  while (var.y < 300)
  {
      multibrot1_core(dep, var);
      var.y++;
  }
  return (NULL);
}

void  *multibrot1_part3(void *param)
{
  t_dep *dep;
  t_set var;

  dep = (t_dep *)param;
  var.y = 300;
  while (var.y < 450)
  {
      multibrot1_core(dep, var);
      var.y++;
  }
  return (NULL);
}

void  *multibrot1_part4(void *param)
{
  t_dep *dep;
  t_set var;

  dep = (t_dep *)param;
  var.y = 450;
  while (var.y < 600)
  {
      multibrot1_core(dep, var);
      var.y++;
  }
  return (NULL);
}
